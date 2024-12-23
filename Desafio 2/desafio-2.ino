const int pinoVerde = 3;      
const int pinoVermelho = 5;   
const int pinoAnalogico = A0;   

void setup() {
  pinMode(pinoVerde, OUTPUT);
  pinMode(pinoVermelho, OUTPUT);
}

void loop() {
  int valorLido = analogRead(pinoAnalogico); 

  if (valorLido < 512) {
    int brilhoVerde = map(valorLido, 0, 511, 0, 255);
    int brilhoVermelho = 0;

    analogWrite(pinoVerde, brilhoVerde);
    analogWrite(pinoVermelho, brilhoVermelho);
  } else {
    int brilhoVermelho = map(valorLido, 512, 1023, 0, 255);
    int brilhoVerde = 0;

    analogWrite(pinoVerde, brilhoVerde);
    analogWrite(pinoVermelho, brilhoVermelho);
  }
}
