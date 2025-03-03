#define led1 26

void setup() {
    Serial.begin(9600);

    pinMode(led1, OUTPUT);

    Serial.println("Quantas vezes o led vai piscar? ");
}

void loop() {

    String vezes = Serial.readString();
    vezes.trim();
    int numVezes = vezes.toInt();

    if(numVezes > 0){
        for(int x = 1; x <= numVezes; x++){
            digitalWrite(led1, HIGH);
            delay(1000);
            digitalWrite(led1, LOW);
            delay(1000);
        }
        numVezes = 0;
    }

}