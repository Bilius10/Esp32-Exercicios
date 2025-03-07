#include <Wire.h>
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

String operador;
String numero1;
String numero2;
int repetir = 1;

void tela(String algo){
  lcd.print(algo);
}
double operacoes(char operation, double n1 = 0, double n2 = 0) {
    switch (operation) {
        case '/': return (n2 != 0) ? n1 / n2 : 0;
        case '*': return n1 * n2;
        case '+': return n1 + n2;
        case '-': return n1 - n2;
        default: return 0;
    }
}

void processo(char key) {
    switch (key) {
        case '/':
        case '*':
        case '-':
        case '+':
            operador = key;
            tela(operador);
            repetir++;
            break;

        case 'c':
            lcd.clear();
            repetir = 1;
            numero1 = "";
            numero2 = "";
            operador = 0;
            break;

        case '=':
            if (numero1.length() > 0 && numero2.length() > 0) {
                double aux = operacoes(operador, atof(numero1.c_str()), atof(numero2.c_str()));

                char buffer[16];
                snprintf(buffer, sizeof(buffer), "%.2f", aux);
                numero1 = String(buffer);
                numero2 = "";

                lcd.clear();
                lcd.print(numero1);
                repetir = 2;
            }
            break;

        default:
            if (repetir == 1) {
                numero1 += key;
                tela(numero1);
            } else if (repetir == 2) {
                numero2 += key;
                tela(numero2);
            } else {
                repetir = 1;
            }
    }
}

void loop() {
    char key = keypad.getKey();

    if (key != NO_KEY) {
        processo(key);
    }
}