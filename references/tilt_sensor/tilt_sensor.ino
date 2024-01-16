#include <Wire.h>
#include <ESP32Servo.h>

const int sensorPin = 5; // Chân số D5 trên ESP32
int threshold = 500;    // Ngưỡng để xác định nghiêng, bạn có thể điều chỉnh giá trị này

void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);

}

void loop() {
  int sensorValue = digitalRead(sensorPin);

  if (sensorValue == HIGH) {
    Serial.println("Cảm biến đang ở trạng thái nghiêng.");
    // Thực hiện các hành động cần thiết khi cảm biến nghiêng
  } else {
    Serial.println("Cảm biến đang ở trạng thái không nghiêng.");
    // Thực hiện các hành động cần thiết khi cảm biến không nghiêng
  }

  delay(10); // Đợi một khoảng thời gian trước khi đọc lại giá trị
}
