#define potenciometro 25
void setup() {
    Serial.begin(9600);
    pinMode(potenciometro, INPUT);
}

void loop() {

    int result = analogRead(potenciometro);
    Serial.println(result);
}
