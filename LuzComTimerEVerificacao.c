#include <TM1637.h>

#define LED 25

#define CLK 27
#define DIO 26
#define LDR_PIN 14

TM1637 tm(CLK, DIO);


void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);

  pinMode(LDR_PIN, INPUT);

  tm.init();
  tm.set(BRIGHT_TYPICAL);
}

unsigned int counter = 0;
boolean ligado = false;

void verificar(boolean teste){

  if (digitalRead(LDR_PIN) == HIGH && teste == false || digitalRead(LDR_PIN) == LOW && teste == true) {
    Serial.println("certo");
  }else{
    Serial.println("Erro, timer com problema");
  }

}

void loop() {

  tm.display(0, (counter / 1000) % 10);
  tm.display(1, (counter / 100) % 10);
  tm.display(2, (counter / 10) % 10);
  tm.display(3, counter % 10);

  counter++;
  if (counter == 100) {
    counter = 0;
    if(ligado ==  false){
      digitalWrite(LED, HIGH);
      ligado = true;
    }else{
      digitalWrite(LED, LOW);
      ligado = false;
    }
  }
  verificar(ligado);
 
  delay(100);
  
}
