#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define led 26
#define sensorMove 27
#define LDR_PIN 21


void setup() {
    Serial.begin(9600);

    pinMode(led, OUTPUT);
    pinMode(sensorMove, INPUT);
    pinMode(LDR_PIN, INPUT);

    Wire.begin(14, 12);
    lcd.init();
    lcd.backlight();
}

void Tela(){
    
    lcd.setCursor(0,0);
    lcd.print((digitalRead(LDR_PIN) == HIGH) ? "Luz acendera" : "Luz nao acendera");
    lcd.setCursor(0,1);
    lcd.print("Claridade: " + String((digitalRead(LDR_PIN) == HIGH) ? "Baixa" : "Alta"));

    delay(1000);
    lcd.clear();

}

void loop() {

  if(digitalRead(LDR_PIN) == HIGH){

    digitalWrite(led, (digitalRead(sensorMove) == HIGH) ? HIGH : LOW);
    
  }

  Tela();

}
