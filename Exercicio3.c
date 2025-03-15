#include <WiFi.h>
#include <ESPping.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado ao WiFi");
}

void loop() {
  int ret = Ping.ping("www.google.com");

  if (ret > 0) {
    Serial.printf("Response time: %d/%.2f/%d ms\n", Ping.minTime(), Ping.averageTime(), Ping.maxTime());
  } else {
    Serial.println("Erro");
  }

  delay(2000);
}
