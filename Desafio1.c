#include <LiquidCrystal_I2C.h>

#define led1 25
#define led2 26
#define led3 32
#define led4 33
#define pot 15

LiquidCrystal_I2C lcd(0X27, 16, 2);

void setup() {

    Serial.begin(115200);
    Wire.begin(22,23);
    lcd.init();
    lcd.backlight();

    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(pot, INPUT);
}

void tela(int num){

    lcd.print("Led "+String(num));
    delay(2000);
    lcd.clear();
}

void loop() {

    int numero = analogRead(pot);

    if(numero <= 1000){
        digitalWrite(led1, HIGH);
        tela(1);
        digitalWrite(led1, LOW);
    }else if(numero <= 2000){
        digitalWrite(led2, HIGH);
        tela(2);
        digitalWrite(led2, LOW);
    }else if(numero <= 3000){
        digitalWrite(led3, HIGH);
        tela(3);
        digitalWrite(led3, LOW);
    }else{
        digitalWrite(led4, HIGH);
        tela(4);
        digitalWrite(led4, LOW);
    }


}