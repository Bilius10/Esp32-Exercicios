#include <Arduino.h>
#include <WiFi.h>
#include <DHTesp.h>
#include <PubSubClient.h>


const char* ssid = "Wokwi-GUEST";
const char* password = "";


// Definindo variáveis para conectar ao broker MQTT
const char* mqtt_broker = "broker.emqx.io";
const int mqtt_port = 1883;


DHTesp dhtSensor;


// instanciando o cliente MQTT
WiFiClient espClient;
PubSubClient client(espClient);


void setup(){


 Serial.begin(115200);
 dhtSensor.setup(13, DHTesp::DHT22);


 //configuração WiFi
 WiFi.begin(ssid, password);
 Serial.println("Conectando na rede Wifi");
 while(WiFi.status() != WL_CONNECTED){
   delay(500);
   Serial.print(".");
 }
 Serial.println();
 Serial.println("Contectado");


 //configuração do cliente MQTT
 client.setServer(mqtt_broker, mqtt_port);
 Serial.println("Conectando ao broker MQTT");
 while(!client.connected()){
   Serial.print(".");
   if(client.connect("ESP32Client-8787afd")){
     Serial.println("Conectado ao broker MQTT");
   }else{
     Serial.print("Falha na conexão, rc=");
     delay(2000);
   }
 }
 Serial.println("Conectado ao broker MQTT");


}


void loop(){
 //capturando temperatura e humidade
 float temperatura = dhtSensor.getTemperature();
 float umidade = dhtSensor.getHumidity();


 String payload = "Temperatura: " + String(temperatura) + ", Umidade :" + String(umidade);


 client.publish("senai/iot", payload.c_str());


 delay(2000);
}
