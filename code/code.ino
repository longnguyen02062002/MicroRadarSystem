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

void loop () {
  for (angle=0; angle<=180; angle++) {
    myServo.write(angle);
    delay(10);
  }

  for (angle=180; angle>=0; angle--) {
    myServo.write(angle);
    delay(10);
  }
  delay(1000);

  digitalWrite (trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  String disp = String (distance);

  Serial.print ("Distance: ");
  Serial.print (disp);
  Serial.println (" cm");
  delay (1000);

  //SSD1306
  display.setTextSize(1);      // Kích thước chữ
  display.setTextColor(SSD1306_WHITE); // Màu chữ
  display.setCursor(0,0);     // Đặt vị trí in chữ
  display.print(F("Distance: "));
  display.print(disp);
  display.println(F(" cm"));

  display.display();
  delay(2000); // Hiển thị "Hello World" trong 2 giây, sau đó xóa màn hình
  display.clearDisplay();
}
