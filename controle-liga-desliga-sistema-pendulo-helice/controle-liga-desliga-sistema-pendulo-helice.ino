/*
 * Controlador liga/desliga para um sistema pendulo-helice
 * Desenvolvido por Clovis Fritzen em 10/10/2016
 * Mais informacoes em www.FritzenLab.com.br
*/

/*
// Limites dos potenciômetros de feedback: 

// Potenciômetro 1: total 10200 ohms, curso de 3670 até 5470 ohms. 
//Limites: 35,98% até 53,62% (368 até 549)

// Potenciômetro 2: total 10280 ohms, curso de 3450 até 5430 ohms
//Limites: 33,56% até 52,82% (343 até 540)
*/

#define motorpin  9 // pino do PWM do motor  
#define analogin A1 // potenciometro de referencia do usuário
#define pinofeedback A2 // potenciometro de realimentação de posição

int referenciaposicao; // Potenciometro que define a posição desejada pelo USUARIO
int percentualpwm; // Valor do PWM aplicado ao motor
int feedback; // realimentação da posição do motor
int percentualfeedback; // percentual da posição do motor
int percentualreferencia; // percentual da referencia do usuário
int erro = 0;

void setup() {
  // nothing happens in setup
  pinMode(motorpin, OUTPUT);
}

void loop() {

referenciaposicao = analogRead(analogin);
feedback = analogRead(pinofeedback);

percentualfeedback = map(feedback, 387, 534, 0, 100);
percentualreferencia = map(referenciaposicao, 0, 1023, 0, 100);
 


if (percentualfeedback >= percentualreferencia){
 digitalWrite(motorpin, LOW);
} else {
  digitalWrite(motorpin, HIGH);
  
}
  

delay(8);  
}


