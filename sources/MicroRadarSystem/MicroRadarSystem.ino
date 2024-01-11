#include <Wire.h>
#include <ESP32Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define echoPin 2
#define trigPin 4

Servo myServo;
int servoPin = 18;
int angle = 0;
int dir = 1; //dir = -1 ,1  quay thuan nguoc chieu kim dong ho

long duration, distance;

void setup () {
  myServo.attach(servoPin);
  Serial.begin(115200);
  //Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //SSD1306
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Hiển thị thông báo khởi động
  display.display();
  delay(2000);
  display.clearDisplay();
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Vong lap 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void loop () {
 
  //--------------------------------------------------------------------------------------
  //Xu ly quet thuan/dao chieu kim dong ho cua dong co servo 
  // Canh tay radar quay mot don vi goc
  //--------------------------------------------------------------------------------------
  {
    angle = angle + dir;
    if (angle >= 180) { dir = -1;} // dao chieu quay;
    if (angle <= 0) { dir = +1;} // dao chieu quay;
    myServo.write(angle);
  }
  delay(10);

  //--------------------------------------------------------------------------------------
  //Do khoang cach nho cam bien sieu am HC-SR04
  //--------------------------------------------------------------------------------------
  {
    digitalWrite (trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration / 58.2;
    //String disp = String (distance);

    Serial.print ("Distance: ");
    Serial.print (distance);
    Serial.println (" cm");
    delay (10);
  }  

  //--------------------------------------------------------------------------------------
  //Hien thi ket qua ra man hinh OLED SSD1306
  //--------------------------------------------------------------------------------------
  {
    display.setTextSize(1);      // Kích thước chữ
    display.setTextColor(SSD1306_WHITE); // Màu chữ
    display.setCursor(0,0);     // Đặt vị trí in chữ
    display.print(F("Distance: "));
    display.print(distance);
    display.println(F(" cm"));

    display.display();
    delay(10);
    display.clearDisplay();
  }
}
