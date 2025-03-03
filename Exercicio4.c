void setup() {
    Serial.begin(9600);

    Serial.println("Digite seu nome: ");
}

void loop() {

    if (Serial.available() > 0) {
        String mensagem = Serial.readString();
        mensagem.trim();

        Serial.println("Seja bem-vindo " + mensagem);
    }
}