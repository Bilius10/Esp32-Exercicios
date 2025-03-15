#define LDR_PIN 33
#define rele 26
void setup() {

    Serial.begin(115200);
    pinMode(LDR_PIN, INPUT);
    pinMode(rele, OUTPUT);

}

void loop() {

    if (digitalRead(LDR_PIN) == LOW) {
        digitalWrite(rele, HIGH);
    } else {
        digitalWrite(rele, LOW);
    }
    delay(100);

}