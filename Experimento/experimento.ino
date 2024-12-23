void setup() {
    // Inicializa os pinos:
    pinMode(2, INPUT_PULLUP);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
}

void loop() {
    // Lê o estado do botão:
    int botao;
    botao = digitalRead(2);

    // Controla os LEDs baseado no estado do botão:
    if (botao == 1) { // Botão pressionado
        digitalWrite(11, HIGH); // LED verde aceso
        digitalWrite(12, LOW); // LED vermelho apagado
    } else { // Botão solto
        digitalWrite(11, LOW); // LED verde apagado
        digitalWrite(12, HIGH); // LED vermelho aceso
    }
}