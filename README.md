### 作品介紹

此作品為互動式網站，使用者首先從網頁動畫中感受並進入暫停時刻思緒混亂之際，接續跟隨網頁指示選擇上一次暫停時刻感受與心情對應的圖案與顏色，選定後從後端將訊號傳送給 Arduino RGB LED 做成的雲裝置，根據使用者的選擇呈現出相對應的燈光與音樂表演，象徵只要將混亂的感受嘗試紀錄下來，終能釐清感受背後的根源，撥雲見日

### 系統架構

- 前端：HTML/CSS/JavaScript  
- 後端：Python/Flask  
- Arduino：WS2812B(NeoPixel)，USB 接收 Python 訊號
  
( 啟動時須將數據線插在 usb_port 並至 app.py 修改 port_number )

