from flask import Flask, request, render_template, jsonify, send_file
from flask_cors import CORS
import serial
from google.oauth2 import service_account
from googleapiclient.discovery import build
from googleapiclient.http import MediaFileUpload
import io
import qrcode
import os

app = Flask(__name__, template_folder='templates')
CORS(app, resources={r"*": {"origins": "http://127.0.0.1:8000"}}, supports_credentials=True) #跨網域設定

#upload count
global upload_count
upload_count = 1

serialInst = serial.Serial()
serialInst.baudrate = 9600
serialInst.port = "COM3"
serialInst.open()





@app.route("/")
def root():
    return render_template("new.html")

@app.route('/api/uploadImg', methods=['GET'])
def upload_img() :
    global upload_count
    UPLOAD_FOLDER = '1E03N9nwRI04mOu0pEs2QHWTYCz9253dx'
    SCOPES = ['https://www.googleapis.com/auth/drive']
    SERVICE_ACCOUNT_FILE = 'google_auth.json'

    # 建立憑證物件
    creds = service_account.Credentials.from_service_account_file(
        SERVICE_ACCOUNT_FILE, scopes=SCOPES)

    service = build('drive', 'v3', credentials=creds)

    base_directory = 'C:/Users/User/Downloads'
    filename = f"image_{upload_count}.jpg"
    file_path = os.path.join(base_directory, filename)
    media = MediaFileUpload(file_path)
    file = {'name': filename, 'parents': [UPLOAD_FOLDER]}

    print("正在上傳檔案...")
    print("id = ", upload_count)
    file_id = service.files().create(body=file, media_body=media).execute()
    uploaded_file_id = file_id['id']
    print('雲端檔案ID：' + str(file_id['id']))
    upload_count += 1

    # 生成包含文件 ID 的 QR Code
    qr = qrcode.QRCode(
        version=1,
        error_correction=qrcode.constants.ERROR_CORRECT_L,
        box_size=5,
    )
    qr.add_data(f'https://drive.google.com/file/d/{uploaded_file_id}')
    qr.make(fit=True)
    qr_img = qr.make_image(fill_color="black", back_color="white")

    # 转换为 Pillow 图片对象并处理背景透明
    img_pil = qr_img.convert('RGBA')  # 转换为 RGBA 模式
    datas = img_pil.getdata()

    # 将白色背景转为透明
    new_data = []
    for item in datas:
        if item[:3] == (255, 255, 255):  # 如果像素为白色
            new_data.append((255, 255, 255, 0))  # 将其设为透明
        else:
            new_data.append(item)

    img_pil.putdata(new_data)

    # 保存处理后的图片到内存中
    img_byte_array = io.BytesIO()
    img_pil.save(img_byte_array, format='PNG')
    img_byte_array.seek(0)

    # 返回处理后的图片
    return send_file(img_byte_array, mimetype='image/png')

@app.route('/api/sendData', methods=['POST'])
def send_data():
    try:
        data = request.get_json()
        value = data.get('product')
        print("Received data:", value)
        serialInst.write(str(value).encode('utf-8'))
        print('Data sent to Arduino')

        if serialInst.is_open:
            return 'Data sent to Arduino'
        else:
            return 'Serial port is not open'

    except Exception as e:
        error_message = f"Error occurred: {str(e)}"
        ###print(error_message)
        return error_message, 500
    
    
if __name__ == '__main__':
    app.run(debug=True)