#include <LiquidCrystal_I2C.h>

#define som 32
#define pot 0
LiquidCrystal_I2C lcd(0X27, 16, 2);

void setup() {

    Serial.begin(115200);
    Wire.begin(22,23);
    lcd.init();
    lcd.backlight();
    pinMode(pot, INPUT);
    pinMode(som, OUTPUT);
}

void tela(int num){

    lcd.print(String(num/10)+"Km/h");
    lcd.clear();
}

void loop() {

    int num = analogRead(pot);
    tela(num);

    if(num > 4000){
        tone(som, 252, 250);
    }else{
        noTone(som);
    }
}