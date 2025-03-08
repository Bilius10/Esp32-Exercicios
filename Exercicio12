#define SOM 26
#define MOVIMENTO 5

void setup() {
  Serial.begin(115200);

  pinMode(SOM, OUTPUT);
  pinMode(MOVIMENTO, INPUT);
}


void loop() {

  int val = digitalRead(MOVIMENTO);

  if(val == HIGH ){
    tone(SOM, 250, 10);
  }

}
