#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);

  Serial.println("I2C Scanner 開始掃描...");
}

void loop() {
  byte error, address;
  int nDevices = 0;

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("找到 I2C 裝置，地址: 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
      
      nDevices++;
    }
  }

  if (nDevices == 0)
    Serial.println("沒有找到 I2C 裝置");
  else
    Serial.println("掃描完成！");

  delay(2000); // 每 2 秒重新掃描
}
