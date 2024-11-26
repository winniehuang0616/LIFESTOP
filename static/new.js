const shapeList = ['jumpp', 'breat', 'linee', 'groww', 'shine']
const colorList = ['reddd', 'yello', 'bluee', 'purpl', 'pinkk']
const idMapping = {
  'jumpp-reddd': 1, 'jumpp-yello': 2, 'jumpp-bluee': 3, 'jumpp-purpl': 4, 'jumpp-pinkk': 5,
  'breat-reddd': 6, 'breat-yello': 7, 'breat-bluee': 8, 'breat-purpl': 9, 'breat-pinkk': 10,
  'linee-reddd': 11, 'linee-yello': 12, 'linee-bluee': 13, 'linee-purpl': 14, 'linee-pinkk': 15,
  'groww-reddd': 16, 'groww-yello': 17, 'groww-bluee': 18, 'groww-purpl': 19, 'groww-pinkk': 20,
  'shine-reddd': 21, 'shine-yello': 22, 'shine-bluee': 23, 'shine-purpl': 24, 'shine-pinkk': 25
};

function reload() {
  location.reload();
}

function start() {
    document.querySelector('.start').style.display = "none";
    const img1 = document.getElementById('1');
    const img2 = document.getElementById('2');
    const img3 = document.getElementById('3');
    const img4 = document.getElementById('4');
    const img5 = document.getElementById('5');
    const trouble_1 = document.getElementById('5-1');
    const trouble_2 = document.getElementById('5-2');
    const main_q = document.getElementById('5-3');
    const img6 = document.getElementById('6');
    const item = document.getElementById('7');
    const box = document.getElementById('8');
    const shape = document.getElementById('9');
    const shape1 = document.getElementById('9-1');
    const next = document.getElementById('9-2');
    const pre = document.getElementById('9-3');
    const nextStep = document.getElementById('9-4');
    const house = document.getElementById('9-5');
    const question = document.getElementById('9-6');
    const question_1 = document.getElementById('9-7');

    setTimeout(function() {
      img1.style.display = "block";
    }, 1000);

    setTimeout(function() {
      img2.style.display = "block";
    }, 1500);

    setTimeout(function() {
      img3.style.display = "block";
    }, 2000);

    setTimeout(function() {
      img4.style.display = "block";
    }, 2500);

    setTimeout(function() {
      img5.style.display = "block";
    }, 3000);

    setTimeout(function() {
      trouble_1.style.display = "block";
    }, 3500);

    setTimeout(function() {
      trouble_1.style.display = "none";
      trouble_2.style.display = "block";
    }, 16500);

    setTimeout(function() {
      trouble_2.style.display = "none";
      main_q.style.display = "block";
    }, 18000);

    setTimeout(function() {
      main_q.style.display = "none";
      img6.style.display = "block";
    }, 24000);

    setTimeout(function() {
      item.style.display = "flex";
      box.style.display = "block";
      shape.style.display = "block";
      shape1.style.display = "inline-block";
      next.style.display = "inline-block";
      pre.style.display = "inline-block";
      nextStep.style.display = "inline-block";
      house.style.display = "inline-block";
      question.style.display = "inline-block";
      question_1.style.display = "inline-block";
    }, 24500);
  };

  let shapeIndex = 1;
  let colorIndex = 1;
  
  function plusShape(n) {
      showShape(shapeIndex += n);
  }
  
  function plusColor(n) {
      showColor(colorIndex += n);
  }
  
  function showShape(n) {
      var i;
      var slides = document.getElementsByClassName("shape");
      if (n > slides.length) {shapeIndex = 1}
      if (n < 1) {shapeIndex = slides.length}
      for (i = 0; i < slides.length; i++) {
          slides[i].style.display = "none";
      }
      slides[shapeIndex-1].style.display = "inline-block";
      pickImage(shapeList[shapeIndex-1])
  }
  
  function showColor(n) {

      var i;
      var slides = document.getElementsByClassName("color");
      if (n > slides.length) {colorIndex = 1}
      if (n < 1) {colorIndex = slides.length}
      for (i = 0; i < slides.length; i++) {
          slides[i].style.display = "none";
      }
      slides[colorIndex-1].style.display = "inline-block";
      setColor(colorList[colorIndex-1])
  }
  
  function pickImage(image) {
      let imgElement = document.createElement('img');
      imgElement.src = '../static/new/' + image + '.png';
      imgElement.alt = image;
      imgElement.className = 'product';
      imgElement.id = image + '-null';
      let emptyBox =  document.querySelector('.empty-box');
      emptyBox.innerHTML = '';
      emptyBox.appendChild(imgElement);
  }
  
  function setColor(color) {
      let preProduct = document.querySelector('.product');
      let shape = preProduct.id.split('-')[0];
      let imgElement = document.createElement('img');
      imgElement.src = '../static/new/' + color + '-' + shape + '.png';
      imgElement.alt = color + '-' + shape;
      imgElement.className = 'product';
      imgElement.id = shape + '-' + color;
      let emptyBox =  document.querySelector('.empty-box');
      emptyBox.innerHTML = '';
      emptyBox.appendChild(imgElement);
  }
  
  function resetShape(type) {
      let preProduct = document.querySelector('.product');
      let shape = preProduct.id.split('-')[0];
      let color = preProduct.id.split('-')[1];
      let imgElement = document.createElement('img');
      if (type=='null') {
        imgElement.src = '../static/new/' + shape + '.png';
        imgElement.alt = shape;
        imgElement.className = 'product';
        imgElement.id = shape + '-null';
      }
      else {
        imgElement.src = '../static/new/' + color + '-' + shape + '.png';
        imgElement.alt = shape + '-' + color;
        imgElement.className = 'product';
        imgElement.id = shape + '-' + color;
      }
      let emptyBox =  document.querySelector('.empty-box');
      emptyBox.innerHTML = '';
      emptyBox.appendChild(imgElement);
  }
  
  function check(stage) {
      if (stage == 'first') {
          if (document.querySelector('.empty-box').innerHTML == '') {
              alert('Please Select A Shape')
          }
          else {
              document.querySelector('.color-container').style.display='flex';
              document.querySelector('.shape-container').style.display='none';
              document.querySelector('.first-continue').style.display='none';
              document.querySelector('.second').style.display='block';
              document.getElementById('9-7').style.display='none';
              document.getElementById('9-8').style.display='inline-block';
              setColor(colorList[colorIndex-1]);
          }
      }
      else if (stage == 'second') {
        document.querySelector('.color-container').style.display='none';
        document.querySelector('.second').style.display='none';
        document.getElementById('9-6').style.display='none';
        document.getElementById('9-8').style.display='none';
        document.getElementById('6').style.display = 'none';
        document.querySelector('.cloud-container').style.display='block';
        document.querySelector('.empty-box').style.top = '280px';
        document.querySelector('.empty-box').style.left = '-60px';
        let preProduct = document.querySelector('.product');
        const product = preProduct.id;
        const number = idMapping[product];
        preProduct.style.transform = 'scale(0.8)'
        let shape = preProduct.id.split('-')[0];
        let color = preProduct.id.split('-')[1];
        sendData(number)
        setTimeout(function() {
            document.querySelector('.transfer').style.display = "block";
            let audio = new Audio(`../static/new/start.mp3`);
            audio.play();
        }, 500);
        setTimeout(function() {
            let audio = new Audio(`../static/new/${shape}.mp3`);
            audio.play();
        }, 6500);
        setTimeout(function() {
          let preProduct = document.querySelector('.product');
          let shape = preProduct.id.split('-')[0];
          let color = preProduct.id.split('-')[1];
          document.querySelector('.third').style.display='none';
          document.querySelector('.empty-box').style.display='none';
          document.querySelector('.cloud-container').style.display='none';
          document.querySelector('.house').style.display='none';
          document.querySelector('.word-container').style.display='block';
          document.querySelector('.energy').style.display='inline-block';
          document.querySelector('.qrcodeImage').src = `../static/new/${color}-${shape}-qrcode.png`
      }, 20500);
      }
      else {
        document.querySelector('.word-container').style.display='none';
        document.querySelector('.forth').style.display='none';
        document.querySelector('.final-container').style.display='block';
        const product = document.querySelector('.product');
        let shape = product.id.split('-')[0];
        let color = product.id.split('-')[1];
        document.querySelector('.qrcodeImage').src = `../static/new/${color}-${shape}-qrcode.png`
      }
  }
  
  function back() {
      document.querySelector('.color-container').style.display='none';
      document.querySelector('.shape-container').style.display='block';
      document.querySelector('.second').style.display='none';
      document.querySelector('.first-continue').style.display='inline-block';
      document.querySelector('.empty-box').style.top = '260px';
      document.querySelector('.empty-box').style.left = '55px';
      document.getElementById('9-7').style.display='inline-block';
      document.getElementById('9-8').style.display='none';
      resetShape('null');
  }

  function back2() {
    document.querySelector('.qrcode-container').style.display='none';
    document.querySelector('.color-container').style.display='flex';
    document.querySelector('.second').style.display='block';
    document.querySelector('.third').style.display='none';
    document.querySelector('.empty-box').style.top = '260px';
    document.querySelector('.empty-box').style.left = '55px';
    resetShape('color');
}
  
function sendData(product) {
    fetch('http://127.0.0.1:5000/api/sendData', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
            'Access-Control-Allow-Origin': '*'
        },
        body: JSON.stringify({ product }),
    });
    console.log("send data: ", product)
}