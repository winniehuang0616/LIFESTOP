#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN    6
#define LED_COUNT 100
#define abs(x) ((x)>0?(x):-(x))

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  strip.begin();
  strip.show();
  strip.setBrightness(50);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void delayFun(int wait, int i) {
    delay(wait);
    strip.clear();
    delay(wait/i);
}

void shine(int g1, int r1, int b1, int g2, int r2, int b2, int wait) {
  int steps = 50;
  float rStep = (float)(abs(r2 - r1)) / steps;
  float gStep = (float)(abs(g2 - g1)) / steps;
  float bStep = (float)(abs(b2 - b1)) / steps;

  for (int i=0; i<LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(g1,   r1,   b1)); 
    strip.show();
  }
  delayFun(wait, 1);
  for (int i=0; i<LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(g1+gStep*5,   r1+rStep*5,   b1+bStep*5)); 
    strip.show();
  }
  delayFun(wait, 2);
  for (int i=0; i<LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(g1+gStep*30,   r1+rStep*30,  b1+bStep*30)); 
    strip.show();
  }
  delayFun(wait, 1);
  // 大雲
  for (int i=0; i<44; i++) {
    strip.setPixelColor(i, strip.Color(g1+gStep*10,   r1+rStep*10,  b1+bStep*10)); 
    strip.show();
  }
  delayFun(wait, 3);
  // 中雲 2
  for (int i=73; i<90; i++) {
    strip.setPixelColor(i, strip.Color(g1+gStep*25,   r1+rStep*25,  b1+bStep*25)); 
    strip.show();
  }
  delayFun(wait, 2);
  // 中雲 1
  for (int i=50; i<66; i++) {
    strip.setPixelColor(i, strip.Color(g2,   r2,   b2)); 
    strip.show();
  }
  delayFun(wait, 1);
  // 小雲
  for (int i=93; i<100; i++) {
    strip.setPixelColor(i, strip.Color(g1+gStep*40,   r1+rStep*40,  b1+bStep*40)); 
    strip.show();
  }
  delayFun(wait, 1);
  // 大雲 + 小雲
  for (int i=0; i<44; i++) {
    strip.setPixelColor(i, strip.Color(g1+gStep*35,   r1+rStep*35,  b1+bStep*35)); 
  }
  for (int i=93; i<100; i++) {
    strip.setPixelColor(i, strip.Color(g1+gStep*8,   r1+rStep*8,  b1+bStep*8)); 
  }
  strip.show();
  delayFun(wait, 1);
  // 兩個中雲
  for (int i=50; i<66; i++) {
    strip.setPixelColor(i, strip.Color(g1+gStep*30,   r1+rStep*30,  b1+bStep*30)); 
  }
  for (int i=73; i<90; i++) {
    strip.setPixelColor(i, strip.Color(g1+gStep*15,   r1+rStep*15,  b1+bStep*15)); 
  }
  strip.show();
  delayFun(wait, 1);
  // 大雲下面
  for (int i=0; i<23; i++) {
    strip.setPixelColor(i, strip.Color(g1+gStep*22,   r1+rStep*22,  b1+bStep*22)); 
    strip.show();
  }
  delayFun(wait, 3);
  // 兩個中雲下面
  for (int i=50; i<58; i++) {
    strip.setPixelColor(i, strip.Color(g1+gStep*37,   r1+rStep*37,  b1+bStep*37)); 
  }
  for (int i=73; i<82; i++) {
    strip.setPixelColor(i, strip.Color(g1+gStep*37,   r1+rStep*37,  b1+bStep*37)); 
  }
  strip.show();
  delayFun(wait, 1);
  //小雲下面
  for (int i=93; i<97; i++) {
    strip.setPixelColor(i, strip.Color(g1+gStep*17,   r1+rStep*17,  b1+bStep*17)); 
    strip.show();
  }
  delayFun(wait, 2);
  for (int i=0; i<LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(g2,   r2,   b2)); 
    strip.show();
  }
  delayFun(wait, 1);
  for (int i=0; i<LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(g1,   r1,   b1)); 
    strip.show();
  }
  delayFun(wait, 2);
}

void grow(int baseR, int baseG, int baseB, int flowR, int flowG, int flowB, int wait) {

  for (int i=0; i<LED_COUNT; i++) {strip.setPixelColor(i, strip.Color(baseR, baseG, baseB));} 
  strip.show();

  for (int i = 0; i < 3; i++) {
    int r = map(i, 0, 2, flowR, 255);
    int g = map(i, 0, 2, flowG, 255);
    int b = map(i, 0, 2, flowB, 255);

      if (i % 2 == 0) {
        strip.setPixelColor(0, strip.Color(r, g, b)); 
        strip.setPixelColor(1, strip.Color(r, g, b)); 
        strip.setPixelColor(2, strip.Color(r, g, b)); 
        for (int i=3; i<LED_COUNT; i++) {
          strip.setPixelColor(i, strip.Color(r, g, b)); 
          strip.setPixelColor(i-3, strip.Color(baseR, baseG, baseB)); 
          strip.show();
          delay(wait);
        }
        for (int i=97; i<LED_COUNT; i++) {
          strip.setPixelColor(i, strip.Color(baseR, baseG, baseB)); 
          strip.show();
        }
      }
      else {
        strip.setPixelColor(99, strip.Color(r, g, b)); 
        strip.setPixelColor(98, strip.Color(r, g, b)); 
        strip.setPixelColor(97, strip.Color(r, g, b)); 
        for (int i=96; i>=0; i--) {
          strip.setPixelColor(i, strip.Color(r, g, b)); 
          strip.setPixelColor(i+3, strip.Color(baseR, baseG, baseB)); 
          strip.show();
          delay(wait);
        }
        for (int i=0; i<2; i++) {
          strip.setPixelColor(i, strip.Color(baseR, baseG, baseB)); 
          strip.show();
        }
      }
  }
}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
  for(int i=0; i<50; i++) {
    strip.setPixelColor(50+i, strip.Color(0,   0,   0));
    strip.setPixelColor(49-i, strip.Color(0,   0,   0)); 
    strip.show();
    delay(wait);
  }
}

void colorWipe2(uint32_t color, int wait) {
  for(int i=0; i<50; i++) {
    strip.setPixelColor(50+i, color);
    strip.setPixelColor(49-i, color); 
    strip.show();
    delay(50);
  }
  for(int i=0; i<50; i++) {
    strip.setPixelColor(i, strip.Color(0,0,0));
    strip.setPixelColor(99-i, strip.Color(0,0,0)); 
    strip.show();
    delay(50);
  }
}

void singleLine(uint32_t color, int wait) {

  // 1-44
  for(int i=0; i<44; i++) {
    strip.setPixelColor(i, color);   
    strip.show();                   
    delay(wait-10);                  
  }
  for(int i=43; i>=0; i--) {
    strip.setPixelColor(i, strip.Color(0,0,0));   
    strip.show();                   
    delay(wait);                  
  }   
  // 51-66
  for(int i=50; i<66; i++) {
    strip.setPixelColor(i, color);  
    strip.show();                  
    delay(wait);             
  }
  for(int i=65; i>=50; i--) {
    strip.setPixelColor(i, strip.Color(0,0,0));  
    strip.show();                  
    delay(wait);             
  }
  // 74-90
  for(int i=73; i<90; i++) {
    strip.setPixelColor(i, color); 
    strip.show();                      
    delay(wait);                           
  }
  for(int i=89; i>=73; i--) {
    strip.setPixelColor(i, strip.Color(0,0,0)); 
    strip.show();                      
    delay(wait);                           
  }
  // 94-100
  for(int i=93; i<100; i++) {
    strip.setPixelColor(i, color); 
    strip.show();                      
    delay(wait+10);                           
  }
  for(int i=99; i>=93; i--) {
    strip.setPixelColor(i, strip.Color(0,0,0)); 
    strip.show();                      
    delay(wait+10);                           
  }
  strip.clear();
  colorWipe2(color, wait);
}

void theaterChase(uint32_t color, int wait, int space) {
  for(int a=0; a<10; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<strip.numPixels(); c += space) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}

void generateRandomArray(int array[], int size) {
  // 初始化数组
  for (int i = 0; i < size; i++) {
    array[i] = i;
  }
  
  // 随机洗牌算法
  for (int i = size - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

void jump(uint32_t color, int wait) {
  int location[LED_COUNT];
  generateRandomArray(location, 100);
  for(int i=0; i<20; i++) {
    strip.setPixelColor(location[i], color);
    strip.show();                          
    delay(wait);  
    strip.clear();
  }
}

void dance(uint32_t color, int wait) {
  int location[LED_COUNT];
  generateRandomArray(location, 100);
  for (int k=0; k<3; k++) {
    for (int t=0; t<10; t++) {
      strip.setPixelColor(location[t], color);
      strip.show();                          
      delay(wait); 
    }
    for(int i=10; i<50; i+=2) {
      strip.setPixelColor(location[i], color);
      strip.show();                          
      delay(wait); 
      strip.setPixelColor(location[i+1], color);
      strip.show();                          
      delay(wait); 
      strip.setPixelColor(location[i-10], strip.Color(0,0,0));
      strip.show();                          
      delay(wait);
      strip.setPixelColor(location[i-9], strip.Color(0,0,0));
      strip.show();                          
      delay(wait);
    }
  }
}
void fadeToColor(int startR, int startG, int startB, int endR, int endG, int endB, int duration) {
  int steps = 20; // Number of steps in the fade
  int delayTime = duration / steps;

  for (int i = 0; i <= steps; i++) {
    int r = map(i, 0, steps, startR, endR);
    int g = map(i, 0, steps, startG, endG);
    int b = map(i, 0, steps, startB, endB);
    for (int bulb=0; bulb<LED_COUNT; bulb++) {
      strip.setPixelColor(bulb, strip.Color(r, g, b));
    }
    strip.show();
    delay(delayTime);
  }
}

void fadeToColor1(int startR, int startG, int startB, int endR, int endG, int endB, int duration) {
  int steps = 20; // Number of steps in the fade
  int delayTime = duration / steps;

  for (int i = 0; i <= steps; i++) {
    int r = map(i, 0, steps, startR, endR);
    int g = map(i, 0, steps, startG, endG);
    int b = map(i, 0, steps, startB, endB);
    for (int bulb=0; bulb<LED_COUNT; bulb+=4) {
      strip.setPixelColor(bulb, strip.Color(r, g, b));
    }
    strip.show();
    delay(delayTime);
  }
}

void fadeToColor2(int startR, int startG, int startB, int endR, int endG, int endB, int duration) {
  int steps = 20; // Number of steps in the fade
  int delayTime = duration / steps;

  for (int i = 0; i <= steps; i++) {
    int r = map(i, 0, steps, startR, endR);
    int g = map(i, 0, steps, startG, endG);
    int b = map(i, 0, steps, startB, endB);
    for (int bulb=1; bulb<LED_COUNT; bulb+=4) {
      strip.setPixelColor(bulb, strip.Color(r, g, b));
    }
    strip.show();
    delay(delayTime);
  }
}

void fadeToColor3(int startR, int startG, int startB, int endR, int endG, int endB, int duration) {
  int steps = 20; // Number of steps in the fade
  int delayTime = duration / steps;

  for (int i = 0; i <= steps; i++) {
    int r = map(i, 0, steps, startR, endR);
    int g = map(i, 0, steps, startG, endG);
    int b = map(i, 0, steps, startB, endB);
    for (int bulb=2; bulb<LED_COUNT; bulb+=4) {
      strip.setPixelColor(bulb, strip.Color(r, g, b));
    }
    strip.show();
    delay(delayTime);
  }
}

void fadeToColor4(int startR, int startG, int startB, int endR, int endG, int endB, int duration) {
  int steps = 20; // Number of steps in the fade
  int delayTime = duration / steps;

  for (int i = 0; i <= steps; i++) {
    int r = map(i, 0, steps, startR, endR);
    int g = map(i, 0, steps, startG, endG);
    int b = map(i, 0, steps, startB, endB);
    for (int bulb=3; bulb<LED_COUNT; bulb+=4) {
      strip.setPixelColor(bulb, strip.Color(r, g, b));
    }
    strip.show();
    delay(delayTime);
  }
}

void loop() {
  if (Serial.available() > 0) {

    String msg = Serial.readStringUntil('\n');
    msg.trim();

    // 開始前
    strip.clear();
    strip.show();
    delay(5000);

    // 單色單點跳躍
    if (msg == "1") {
        jump(strip.Color(20,   255,   0), 280);
        strip.clear();
        theaterChase(strip.Color(20,   255,   0), 150, 3);
        strip.clear();
        dance(strip.Color(20,   255,   0), 13);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "2") {
        jump(strip.Color(180,   255,   0), 280);
        strip.clear();
        theaterChase(strip.Color(180,   255,   0), 150, 3);
        strip.clear();
        dance(strip.Color(180,   255,   0), 13);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "3") {
        jump(strip.Color(150,   0,   255), 280);
        strip.clear();
        theaterChase(strip.Color(150,   0,   255), 150, 3);
        strip.clear();
        dance(strip.Color(150,   0,   255), 13);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "4") {
        jump(strip.Color(20,   80,   255), 280);
        strip.clear();
        theaterChase(strip.Color(20,   80,   255), 150, 3);
        strip.clear();
        dance(strip.Color(20,   80,   255), 13);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "5") {
        jump(strip.Color(0,   255,   230), 280);
        strip.clear();
        theaterChase(strip.Color(0,   255,   230), 150, 3);
        strip.clear();
        dance(strip.Color(0,   255,   230), 13);
        strip.clear();
        strip.show();
        delay(2000);
    }

    // 多色呼吸燈
    else if ( msg == "6") {
        fadeToColor(0,0,0,20,255,0,1000);
        fadeToColor(20,255,0,180,255,0,1000);
        fadeToColor(180,255,0,20,255,0,1000);
        fadeToColor1(20,255,0,0,0,0,500);
        fadeToColor2(20,255,0,20,255,0,500);
        fadeToColor3(20,255,0,180,255,0,500);
        fadeToColor4(20,255,0,20,255,0,500);
        fadeToColor1(0,0,0,20,255,0,1000);
        fadeToColor2(20,255,0,180,255,0,1000);
        fadeToColor3(180,255,0,20,255,0,1000);
        fadeToColor4(20,255,0,0,0,0,1000);
        fadeToColor1(20,255,0,0,0,0,1000);
        fadeToColor2(180,255,0,20,255,0,1000);
        fadeToColor3(20,255,0,180,255,0,1000);
        fadeToColor4(0,0,0,20,255,0,1000);
        fadeToColor2(20,255,0,0,0,0,500);
        fadeToColor3(180,255,0,0,0,0,500);
        fadeToColor4(20,255,0,0,0,0,500);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg=="7") {
        fadeToColor(0,0,0,180,255,0,1000);
        fadeToColor(180,255,0,20,255,0,1000);
        fadeToColor(20,255,0,180,255,0,1000);
        fadeToColor1(180,255,0,0,0,0,500);
        fadeToColor2(180,255,0,180,255,0,500);
        fadeToColor3(180,255,0,20,250,0,500);
        fadeToColor4(180,255,0,180,255,0,500);
        fadeToColor1(0,0,0,180,255,0,1000);
        fadeToColor2(180,250,0,20,255,0,1000);
        fadeToColor3(20,250,0,180,255,0,1000);
        fadeToColor4(180,250,0,0,0,0,1000);
        fadeToColor1(180,255,0,0,0,0,1000);
        fadeToColor2(20,250,0,180,255,0,1000);
        fadeToColor3(180,250,0,20,255,0,1000);
        fadeToColor4(0,0,0,180,255,0,1000);
        fadeToColor2(180,255,0,0,0,0,500);
        fadeToColor3(20,255,0,0,0,0,500);
        fadeToColor4(180,255,0,0,0,0,500);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg=="8") {
        fadeToColor(0,0,0,200,200,255,750);
        fadeToColor(200,200,255,150,0,255,750);
        fadeToColor(150,0,255,20,20,255,750);
        fadeToColor(20,20,255,150,0,255,750);
        fadeToColor1(150,0,255,0,0,0,500);
        fadeToColor2(150,0,255,150,0,255,500);
        fadeToColor3(150,0,255,20,150,255,500);
        fadeToColor4(150,0,255,150,0,255,500);
        fadeToColor1(0,0,0,150,0,255,1000);
        fadeToColor2(150,0,255,20,150,255,1000);
        fadeToColor3(20,150,255,150,0,255,1000);
        fadeToColor4(150,0,255,0,0,0,1000);
        fadeToColor1(150,0,255,0,0,0,1000);
        fadeToColor2(20,80,255,150,0,255,1000);
        fadeToColor3(150,0,255,20,80,255,1000);
        fadeToColor4(0,0,0,150,0,255,1000);
        fadeToColor2(150,0,255,0,0,0,500);
        fadeToColor3(20,80,255,0,0,0,500);
        fadeToColor4(150,0,255,0,0,0,500);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg=="9") {
        fadeToColor(0,0,0,20,80,255,1000);
        fadeToColor(20,80,255,0,255,255,1000);
        fadeToColor(0,255,255,20,80,255,1000);
        fadeToColor1(20,80,255,0,0,0,500);
        fadeToColor3(20,80,255,0,255,255,500);
        fadeToColor1(0,0,0,20,80,255,1000);
        fadeToColor2(20,80,255,0,255,255,1000);
        fadeToColor3(0,255,255,20,80,255,1000);
        fadeToColor4(20,80,255,0,0,0,1000);
        fadeToColor1(20,80,255,0,0,0,1000);
        fadeToColor2(0,255,255,20,80,255,1000);
        fadeToColor3(20,80,255,0,255,255,1000);
        fadeToColor4(0,0,0,20,80,255,1000);
        fadeToColor2(20,80,255,0,0,0,500);
        fadeToColor3(0,255,255,0,0,0,500);
        fadeToColor4(20,80,255,0,0,0,500);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "10") {
        fadeToColor(0,0,0,0,250,230,1000);
        fadeToColor(0,250,230,0,255,20,1000);
        fadeToColor(0,255,20,0,250,230,1000);
        fadeToColor1(0,250,230,0,0,0,500);
        fadeToColor3(0,250,230,0,255,20,500);
        fadeToColor1(0,0,0,0,250,230,1000);
        fadeToColor2(0,250,230,0,255,20,1000);
        fadeToColor3(0,255,20,0,250,230,1000);
        fadeToColor4(0,250,230,0,0,0,1000);
        fadeToColor1(0,250,230,0,0,0,1000);
        fadeToColor2(0,255,20,0,250,230,1000);
        fadeToColor3(0,250,230,0,255,20,1000);
        fadeToColor4(0,0,0,0,250,230,1000);
        fadeToColor2(0,250,230,0,0,0,500);
        fadeToColor3(0,255,20,0,0,0,500);
        fadeToColor4(0,250,230,0,0,0,500);
        strip.clear();
        strip.show();
        delay(2000);
    }

    // 單色線性流動
    else if (msg == "11") {
        singleLine(strip.Color(20,   255,   0),45);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "12") {
        singleLine(strip.Color(180,   255,   0),45);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "13") {
        singleLine(strip.Color(150,   0,   255),45);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "14") {
        singleLine(strip.Color(20,   80,   255),45);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "15") {
        singleLine(strip.Color(0,   255,   230),45);
        strip.clear();
        strip.show();
        delay(2000);
    }

    // 雙色流動
    else if (msg == "16") {
        grow(20,255,0, 20,80,255, 49);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "17") {
        grow(180,255,0, 150,0,255, 49);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "18") {
        grow(150,0,255, 150,255,0, 49);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "19") {
        grow(20,80,255, 50,255,0, 49);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "20") {
        grow(0,250,230, 180,0,255, 49);
        strip.clear();
        strip.show();
        delay(2000);
    }

    // 多色閃爍
    else if (msg=="21") {
        shine(20,255,0,140,255,0,250);
        shine(20,255,0,0,255,150,200);
        strip.clear();
        strip.show();
        delay(2000);
    }
    else if (msg == "22") {
        shine(180,255,0,80,255,0,250);
        shine(180,255,0,200,255,80,200);
        strip.clear();
        strip.show();
        delay(2000);
    } 
    else if (msg == "23") {
        shine(20,20,255,200,200,255,250);
        shine(20,20,255,20,150,255,200);
        strip.clear();
        strip.show();
        delay(2000);
    } 
    else if (msg == "24") {
        shine(20,80,255,0,255,255,250);
        shine(20,80,255,150,0,255,200);
        strip.clear();
        strip.show();
        delay(2000);
    } 
    else if (msg == "25") {
        shine(0,255,230,0,255,10,250);
        shine(0,255,230,20,150,80,200);
        strip.clear();
        strip.show();
        delay(2000);
    } 
  }
  else {
    for(int i=0; i<LED_COUNT; i++) {
      strip.setPixelColor(i, strip.Color(127,   127,   127)); 
      strip.show();
    }           
  }
}
