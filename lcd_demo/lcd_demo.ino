#include <LiquidCrystal.h>
#define rs 12
#define en 11
#define d4 5
#define d5 4
#define d6 3
#define d7 2

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    lcd.begin(16, 2);
    lcd.print("hello joe!");
}

void loop() {
    lcd.noDisplay();
    delay(500);
    lcd.display();
    delay(500);
}
