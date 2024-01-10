#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Hiển thị thông báo khởi động
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  display.setTextSize(1);      // Kích thước chữ
  display.setTextColor(SSD1306_WHITE); // Màu chữ
  display.setCursor(0,0);     // Đặt vị trí in chữ
  display.println(F("Hello World!"));

  display.display();
  delay(2000); // Hiển thị "Hello World" trong 2 giây, sau đó xóa màn hình
  display.clearDisplay();
}
