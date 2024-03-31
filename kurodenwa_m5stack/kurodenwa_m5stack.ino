#include <M5Core2.h>

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(60, 80);
  M5.Lcd.printf("JPEG SWITCH");
}

void loop() {
  if (Serial.available() > 0) {
    // シリアルからデータを読み取り
    char receivedChar = Serial.read();

    // 受信したデータをシリアルモニタに表示
    Serial.print("Received: ");
    Serial.println(receivedChar);
    M5.Lcd.clear(TFT_BLACK);
    M5.Lcd.printf("%c", receivedChar);
    if (receivedChar == '1') {
      M5.Lcd.clear(TFT_BLACK);
      M5.Lcd.drawJpgFile(SD, "/1.jpg");
    }
    if (receivedChar == '2') {
      M5.Lcd.clear(TFT_BLACK);
      M5.Lcd.drawJpgFile(SD, "/2.jpg");
    }
    if (receivedChar == '3') {
      M5.Lcd.clear(TFT_BLACK);
      M5.Lcd.drawJpgFile(SD, "/3.jpg");
    }
    if (receivedChar == '4') {
      M5.Lcd.clear(TFT_BLACK);
      M5.Lcd.drawJpgFile(SD, "/4.jpg");
    }
  }
}
