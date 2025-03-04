#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(9600);
    Wire.begin(22, 23);
    lcd.init();
    lcd.backlight();

}


void Hello(){

    lcd.setCursor(2,0);
    lcd.print("Hello World!");
    delay(1000);
    lcd.clear();
}

void loop() {
    Hello ();
}