#define potenciometro 25
#define led1 23
#define led2 22
#define led3 21
#define led4 15

void setup() {
    Serial.begin(9600);
    pinMode(potenciometro, INPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
}

void loop() {

    int result = analogRead(potenciometro);

    Serial.println(result);
    if(result >= 1000){
        digitalWrite(led1, HIGH);
    }else{
        digitalWrite(led1, LOW);
    }

    if(result >= 2000){
        digitalWrite(led2, HIGH);
    }else{
        digitalWrite(led2, LOW);
    }

    if(result >= 3000){
        digitalWrite(led3, HIGH);
    }else{
        digitalWrite(led3, LOW);
    }

    if(result >= 4000){
        digitalWrite(led4, HIGH);
    }else{
        digitalWrite(led4, LOW);
    }

}