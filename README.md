# GIỚI THIỆU VỀ MICRO RADAR SYSTEM

## Mô tả
  
Mô phỏng hoạt động của radar với chức năng phát hiện vật thể từ xa bằng sóng siêu âm.

## Nguyên lý

Sử dụng ESP32 để kích hoạt:
- Bộ cảm biến HC-SR04: Bộ cảm biến này sẽ phát ra 1 sóng siêu âm để đo khoảng cách từ bộ cảm biến tới vị trí vật cản mà sóng siêu âm sẽ va chạm.
- Bộ quay servo: Quay 180 độ xong về vị trí cũ. Bộ cảm biến HC-SR04 sẽ được gắn lên servo này.
- Cảm biến tilt SW-520D: Cảm biến xem vật nghiêng hay không nghiêng.
- Màn hình OLED SSD1306: Hiển thị lên màn hình khoảng cách đo được từ bộ cảm biến HC-SR04, góc quay của servo, thông tin cảm biến nghiêng.

## Video minh họa
[![Micro Radar System Demo Video](https://i9.ytimg.com/vi_webp/MnHhczUm32Q/mq2.webp?sqp=CNyHna0G-oaymwEmCMACELQB8quKqQMa8AEB-AH-CYAC0AWKAgwIABABGEYgWChyMA8=&rs=AOn4CLDh3r6Jc9yTbFvbkfC-dRIggEfd0g)](https://www.youtube.com/watch?v=MnHhczUm32Q)
