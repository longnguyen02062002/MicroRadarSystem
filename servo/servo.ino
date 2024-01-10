#include <ESP32Servo.h>

Servo myServo;
int servoPin = 18;
int angle = 0;
void setup() {
  myServo.attach(servoPin);
  Serial.begin(115200);
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
}