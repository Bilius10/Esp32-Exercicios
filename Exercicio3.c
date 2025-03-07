#include <WiFi.h>
#include <ESPping.h>
#include <LiquidCrystal_I2C.h>

#define led 25

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);

  Wire.begin(32, 33);
  lcd.init();
  lcd.backlight();

  pinMode(led, OUTPUT);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }

  Serial.println("Conectado ao WiFi");
}

void tela(String palavra) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(palavra);
}

void loop() {
  bool ret = Ping.ping("www.google.com");

  if (ret) {
    tela("Google online");
  } else {
    tela("Google offline");
  }

  delay(2000);
}