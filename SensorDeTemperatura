#include <LiquidCrystal_I2C.h>
#include "DHTesp.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int DHT_PIN = 16;
DHTesp dhtSensor;

int tempLimite = 25;  

void setup() {
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  
  Wire.begin(25,26);
  lcd.init();
  lcd.backlight();

  Serial.println("Informe a temperatura limite: ");
  while (Serial.available() == 0) {
    
  }

  String tempString = Serial.readString();
  tempLimite = tempString.toInt();

  lcd.print("Temp limite: ");
  lcd.print(tempLimite);
  delay(2000);  
}

void arCondicionado(String frase) {
  lcd.clear();  
  lcd.print(frase);  
}

void loop() {
 
  TempAndHumidity data = dhtSensor.getTempAndHumidity();
  

  if (data.temperature > tempLimite + 1 || data.temperature < tempLimite - 1) {
  arCondicionado("Ligado");
} else {
  arCondicionado("Desligado");
}
  
  delay(2000);  
}
