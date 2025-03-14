#include <ESP32Servo.h>

Servo myservo;
int potpin = 34; // Ajustado para um pino analógico válido
int val;

#define PIN_LED1 14
#define PIN_LED2 27
#define PIN_MOTOR 18

volatile byte state = LOW;

void setup() {
    Serial.begin(115200);

    myservo.attach(PIN_MOTOR);
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    pinMode(PIN_MOTOR, INPUT);
    attachInterrupt(digitalPinToInterrupt(PIN_MOTOR), blink, FALLING);
}

void loop() {

    digitalWrite(PIN_LED1, state);
    digitalWrite(PIN_LED2, state);


    val = analogRead(potpin);
    val = map(val, 0, 4095, 0, 180);
    myservo.write(val);

    delay(100);
}

void IRAM_ATTR blink() {
    state = !state;
}