#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <DHTesp.h>

const char* SSID = "Wokwi-GUEST"; 
const char* PASSWORD = "";

HTTPClient http;

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int DHT_PIN = 16;
DHTesp dhtSensor;

#define led 26
#define sensorMove 27
#define LDR_PIN 21

String thingSpeak = "https://api.thingspeak.com/update?api_key=MKIT9AMIT0ZQY67A";

void setup() {
    Serial.begin(9600);

    Wire.begin(14, 12);
    lcd.init();
    lcd.backlight();

    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      lcd.print(".");
    }

    lcd.clear();
    lcd.print("Wifi Connected");

    delay(2000);

    pinMode(led, OUTPUT);
    pinMode(sensorMove, INPUT);
    pinMode(LDR_PIN, INPUT);

    dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
}

void Tela() {
    lcd.setCursor(0, 0);
    lcd.print((digitalRead(LDR_PIN) == HIGH) ? "Luz acendera" : "Luz nao acendera");

    lcd.setCursor(0, 1);
    lcd.print("Claridade: " + String((digitalRead(LDR_PIN) == HIGH) ? "Baixa" : "Alta"));

    delay(1000);
}

void loop() {

  if (digitalRead(LDR_PIN) == HIGH) {
    if (digitalRead(sensorMove) == HIGH) {
        digitalWrite(led, HIGH);
    } else {
        digitalWrite(led, LOW);
    }
  }else{
    digitalWrite(led, LOW);
  }
  
  lcd.clear();
  Tela();  
  
  TempAndHumidity data = dhtSensor.getTempAndHumidity();

  http.begin(thingSpeak + "&field2=" + String(data.temperature));  
  int httpCode = http.GET();  
  http.end();  
 
  http.begin(thingSpeak + "&field3=" + String(data.humidity));  
  httpCode = http.GET();  
  http.end();  

}
