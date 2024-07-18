#include "BluetoothSerial.h"

int settime[4] = { 0, 0, 0, 0 };

BluetoothSerial SerialBT;

void setup() {
  // put your setup code here, to run once:
  SerialBT.begin(115200);
  SerialBT.begin("ESP32motor");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (SerialBT.available() > 0) {
    String receivedString = SerialBT.readStringUntil('\n');  // 改行まで読み取る
    if (receivedString.length() != 4) {                    // 受信した文字列が4桁でない場合
      SerialBT.println("Error: Input must be exactly 4 digits.");
    } else {
      bool isValid = true;
      for (int i = 0; i < 4; i++) {
        if (!isdigit(receivedString.charAt(i))) {  // 数字でない文字が含まれているかチェック
          isValid = false;
          break;
        }
      }
      if (!isValid) {
        SerialBT.println("Error: Input must contain only digits.");
      } else {
        for (int i = 0; i < 4; i++) {
          settime[i] = receivedString.charAt(i) - '0';
          SerialBT.println(settime[i]);
        }
        SerialBT.print("Received: ");
        SerialBT.println(receivedString);  // 受信した文字列を出力
      }
    }
  }
}

