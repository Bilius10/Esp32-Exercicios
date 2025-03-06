#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0X27, 16, 2);

#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

const uint8_t ROWS = 4;
const uint8_t COLS = 4;

char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
    {'1', '2', '3', '+'},
    {'4', '5', '6', '-'},
    {'7', '8', '9', '*'},
    {'c', '0', '=', '/'}
};

uint8_t colPins[COLS] = { 18, 5, 17, 16 };
uint8_t rowPins[ROWS] = { 23, 22, 21, 19 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
    Serial.begin(9600);

    Wire.begin(25,26);
    lcd.init();
    lcd.backlight();

}

char operador;
String numero1;
String numero2;
double aux = 0;
int repetir = 1;

double operacoes(char operation, double n1 = 0, double n2 = 0){
    switch (operation){
        case '/': return n1/n2;
        case '*': return n1*n2;
        case '+': return n1+n2;
        case '-': return n1-n2;
    }


}

void processo(){

    switch(key){

        case '/':
        case '*':
        case '-':
        case '+':
          operador = key;
        repetir ++;
        break;

        case 'c':
            lcd.clear();
        repetir = 1;
        break;

        case '=':
            aux = operacoes(operador, double(numero1), double(numero2));
        sprintf(numero1, "%.2f", aux);
        lcd.clear();
        lcd.print(numero1);
        repetir = 2;
        break;

        default:
            if(repetir == 1){
                numero1 += key;
            }else if(repetir == 2){
                numero2 += key;
            }else{
                repetir = 1;
            }
    }

}

void loop() {

    char key = keypad.getKey();

    if (key != NO_KEY) {
        processo();
    }

}