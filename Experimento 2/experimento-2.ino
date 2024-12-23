int pinoLedVerde = 13;
int pinoLedVermelho = 11; 
int valor = 0; 

void setup() {
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    valor = Serial.parseInt(); 

    if (valor == 0) {
      digitalWrite(pinoLedVerde, HIGH);
      digitalWrite(pinoLedVermelho, LOW); 
    } else if (valor == 1) {
      digitalWrite(pinoLedVerde, LOW); 
      digitalWrite(pinoLedVermelho, HIGH); 
    } else if (valor == 2) {
      fadeLEDs(); 
    }
  }
}

void fadeLEDs() {
  for (int brilho = 0; brilho <= 255; brilho++) {
    analogWrite(pinoLedVerde, brilho);
    analogWrite(pinoLedVermelho, 255 - brilho);
    delay(10);
  }

  for (int brilho = 255; brilho >= 0; brilho--) {
    analogWrite(pinoLedVerde, brilho);
    analogWrite(pinoLedVermelho, 255 - brilho);
    delay(10);
  }
}
