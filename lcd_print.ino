// 引入 I2C LCD 的函式庫（PCF8574 代表 I2C 轉接板的晶片型號）
#include "LiquidCrystal_PCF8574.h"

// 設定 LCD 的 I2C 位址為 0x27，並建立一個名為 lcd 的物件來控制它
LiquidCrystal_PCF8574 lcd(0x27);

void setup() {
  // 初始化 LCD，設定為 16 格寬、2 列高
  lcd.begin(16, 2);
  
  // 設定背光亮度（255 為最亮，有些版本僅支援 0 或 1，代表關或開）
  lcd.setBacklight(255);
  
  // 清除螢幕上所有的文字，確保畫面乾淨
  lcd.clear();
}

void loop() {
  // 設定游標位置：(第幾格, 第幾列)
  // 5 代表從左邊數來第 6 格（從 0 開始算）
  // 0 代表第一列（上方那列）
  lcd.setCursor(5, 0);
  
  // 在剛剛設定的位置印出 "jason"
  lcd.print("jason");
  
  // 延遲 1000 毫秒（1 秒），讓程式穩定執行
  delay(1000);
}
