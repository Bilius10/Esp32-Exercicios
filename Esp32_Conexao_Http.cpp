#include <DHTesp.h>
#include <WiFi.h>
#include <HTTPClient.h>

const int DHT_PIN = 15;
DHTesp dhtSensor;

const char* SSID = "Wokwi-GUEST";
const char* PASSWORD = "";
const char* host = "https://api.thingspeak.com/update?api_key=J7636SAFE3689FEL";

HTTPClient http;

void setup() {
  Serial.begin(115200);

  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  WiFi.begin(SSID, PASSWORD);

  Serial.println("Tentando conexão");

  while (WiFi.status() != WL_CONNECTED){
    Serial.println(".");
    delay(100);
  }
  Serial.println("Conectado");
 
}

void loop() {
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();

  String field1 = "&field1=" + String(data.temperature);
  String field2 = "&field2=" + String(data.humidity);

  String url = host + field1 + field2;

  Serial.println(url);
  http.begin(url);

  int httpCode = http.GET();
  if (httpCode > 0) {

    Serial.printf("Código de resposta: %d\n", httpCode);

    String payload = http.getString();
    Serial.println(payload);
  }

  delay(2000); 
}
