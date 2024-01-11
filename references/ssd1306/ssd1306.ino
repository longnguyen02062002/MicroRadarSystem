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
  
  int centerX = SCREEN_WIDTH / 2;
  int centerY = SCREEN_HEIGHT / 2;
  int length = 20; // Chiều dài đoạn góc

  // Tính toán tọa độ đỉnh của góc
  for (int i=1; i<=180; i++) {
    int x2 = centerX + length * cos(PI/(180/i));
    int y2 = centerY + length * sin(PI/(180/i));

    // Vẽ đoạn thẳng từ trung tâm đến đỉnh góc
    display.drawLine(centerX, centerY, x2, y2, SSD1306_WHITE);

    // Hiển thị màn hình
    display.display();

    delay(100);
  }
    display.clearDisplay();
}
