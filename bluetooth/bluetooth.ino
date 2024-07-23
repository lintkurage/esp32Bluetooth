#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_bt");  //Bluetoothの名前設定
}

void loop() {
  SerialBT.println("Hello World!");
  delay(1000);
}