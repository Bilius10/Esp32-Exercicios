#include <stdio.h>

void setup() {

    Serial.begin(115200);

    for(int x = 1; x <= 10; x++){
        Serial.println(x);
        delay(1000);
    }
}

void loop() {


}