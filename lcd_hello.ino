#include "LiquidCrystal_PCF8574.h"

// 定義 LCD 物件，0x27 是 I2C 介面卡常用的位址
LiquidCrystal_PCF8574 lcd(0x27);

void setup() {
  // 初始化 1602 LCD (16格寬, 2列高)
  lcd.begin(16, 2);
  
  // 開啟背光 (255 表示最亮)
  lcd.setBacklight(255);
  
  // 清除螢幕上所有殘留的畫面
  lcd.clear();
  
  // 在第一列 (Row 0) 的第 5 格位置
  lcd.setCursor(5, 0);
  
  // 印出固定不動的名字 "jason"
  lcd.print("jason");

  // 先停 1 秒，讓使用者看清楚名字後再開始跑馬燈
  delay(1000);
}

void loop() {
  // 【跑馬燈邏輯】
  // 使用 for 迴圈讓變數 i 從 15 遞減到 0
  // i 代表 "Hello" 這串字的起始格數 (橫向座標)
  for (int i = 15; i >= 0; i--) {
    
    // 1. 將「筆尖」移到第二列 (Row 1) 的第 i 格
    lcd.setCursor(i, 1);
    
    // 2. 印出移動中的文字 "Hello"
    lcd.print("Hello");
    
    // 3. 延遲 200 毫秒，控制滾動的速度（數字越小跑越快）
    delay(200);
    
    // 4. 【關鍵步驟】清除第二列，準備下一次移動
    // 如果不清除，螢幕會留下一長串的 "Helloooooooo"
    // 我們將游標移回第二列的開頭 (0, 1)
    lcd.setCursor(0, 1);
    
    // 印出 16 個空格，徹底覆蓋掉第二列所有的字，但不會影響第一列的 jason
    lcd.print("                "); 
  }
}
 

 
