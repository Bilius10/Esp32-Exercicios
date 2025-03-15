#include <ESP32Servo.h>

#define inputPin 26
const int servoPin = 18;

Servo servo;

void setup() {

  Serial.begin(115200);
  servo.attach(servoPin, 500, 2400);
  pinMode(inputPin, INPUT);

}

int pos = 0;
int val = 0;

void loop() {
  val = digitalRead(inputPin);

  if (val == HIGH) {
    for (pos = 0; pos <= 180; pos += 1) {
      servo.write(pos);
      delay(15);
    }
    delay(3000);
    for (pos = 180; pos >= 0; pos -= 1) {
      servo.write(pos);
      delay(15);
    }
   val = LOW;
  }
  delay(10);
}

