int vermelho = 13;
int amarelo = 12;
int verde = 11;
int peVermelho = 7;
int peVerde = 6;
int botao = 2;
unsigned long tempoInicio;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(peVermelho, OUTPUT);
  pinMode(peVerde, OUTPUT);
  pinMode(botao, INPUT_PULLUP); 
  tempoInicio = millis(); 
}

void loop() {
  unsigned long tempoAtual = millis();
  unsigned long tempoDecorrido = tempoAtual - tempoInicio;
  
  digitalWrite(verde, HIGH);
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, LOW);
  digitalWrite(peVermelho, HIGH);
  digitalWrite(peVerde, LOW);

  if (digitalRead(botao) == LOW && tempoDecorrido < 5000) {
    delay(50); 
    if (digitalRead(botao) == LOW) {
      tempoInicio -= 2500;
    }
  }
  
  if (tempoDecorrido >= 5000) {
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, HIGH);
    delay(2000);
    digitalWrite(peVermelho, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, HIGH);
    digitalWrite(peVerde, HIGH);
    delay(5000);
    digitalWrite(peVerde, LOW);
    digitalWrite(peVermelho, HIGH);
    tempoInicio = millis();
  }
}
