# GIỚI THIỆU VỀ MICRO RADAR SYSTEM

## Mô tả
  
Mô phỏng hoạt động của radar với chức năng phát hiện vật thể từ xa bằng sóng siêu âm.

## Nguyên lý

Sử dụng ESP32 để kích hoạt:
- Bộ cảm biến HC-SR04: Bộ cảm biến này sẽ phát ra 1 sóng siêu âm để đo khoảng cách từ bộ cảm biến tới vị trí vật cản mà sóng siêu âm sẽ va chạm.
- Bộ quay servo: Quay 180 độ xong về vị trí cũ. Bộ cảm biến HC-SR04 sẽ được gắn lên servo này.
- Màn hình OLED SSD1306: Hiển thị lên màn hình khoảng cách đo được từ bộ cảm biến HC-SR04.
