#include <LiquidCrystal_PCF8574.h> // 引入 I2C LCD 的函式庫（這是別人寫好的工具包）

// 建立一個 LCD 物件，並設定 I2C 位址為 0x27
// 就像是告訴 Arduino：「這塊螢幕的名字叫 lcd，它的身分證字號是 0x27」
LiquidCrystal_PCF8574 lcd(0x27);  

int t = 0; // 宣告一個變數 t，用來儲存秒數，初始值設為 0

void setup() {
  // setup 區塊：開機時只會執行一次
  
  lcd.begin(16, 2);      // 初始化螢幕，告訴它這是一塊 16 格寬、2 列高的螢幕
  lcd.setBacklight(255); // 開啟螢幕背光（255 為最亮，0 為關閉）
}

void loop() {
  // loop 區塊：裡面的程式碼會由上而下不斷地重複執行
  
  lcd.clear();           // 清除螢幕上所有的文字，讓畫面變回空白
  
  lcd.setCursor(0, 0);   // 設定接下來要寫字的位置：第 1 欄 (0), 第 1 列 (0)
  
  lcd.print(t);          // 在目前的游標位置印出變數 t 的數值
  
  delay(1000);           // 讓程式暫停 1000 毫秒（也就是 1 秒鐘）
  
  t = t + 1;             // 將變數 t 的數值加 1（為下一秒做準備）
  
  // 執行到這裡後，會立刻跳回 loop 的第一行 lcd.clear() 繼續執行
}
