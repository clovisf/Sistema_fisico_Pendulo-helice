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


// Variables used to avoid using the delay function
unsigned long timet;
unsigned long tempoativo1inicio;
unsigned long tempoativo2inicio;
unsigned long tempoativo3inicio;
unsigned long tempoativo1final;
unsigned long tempoativo2final;
unsigned long tempoativo3final;
unsigned long tempototal1;
unsigned long tempototal2;
unsigned long tempototal3;

unsigned long previousTime;
unsigned long previousTime2;
unsigned long previousTime3;
boolean enterFunction= true;
boolean enterFunction2 = true;
boolean enterFunction3 = true;
//-----------------------

#define motorpin  9 // pino do PWM do motor  
#define piscaled 13 // LED conectado ao pino 13 do Arduino
#define analogin A1 // potenciometro de referencia do usuário
#define pinofeedback A2 // potenciometro de realimentação de posição

long referenciaposicao; // Potenciometro que define a posição desejada pelo USUARIO
long percentualpwm; // Valor do PWM aplicado ao motor
long feedback; // realimentação da posição do motor
long percentualfeedback; // percentual da posição do motor
long percentualreferencia; // percentual da referencia do usuário
int erro = 0;
boolean ledState = false;

void setup() {
  // nothing happens in setup
  pinMode(motorpin, OUTPUT);
  pinMode(piscaled, OUTPUT);
  Serial.begin(115200);
}

void loop() {

   timet = micros();
  if (enterFunction == true){
    previousTime= timet;
    tempoativo1inicio= micros();
    //Serial.println(previousTime); // for debugging

    // Start your first code below 
    //-----------------------
    

referenciaposicao = analogRead(analogin);
feedback = analogRead(pinofeedback);

percentualfeedback = map(feedback, 387, 650, 0.00, 100.00);
percentualreferencia = map(referenciaposicao, 0, 1023, 0.00, 100.00);
 


if (percentualfeedback >= percentualreferencia){
 digitalWrite(motorpin, LOW);
} else {
  digitalWrite(motorpin, HIGH);
  
}
  tempoativo1final= micros();
  tempototal1 = tempoativo1final - tempoativo1inicio;
  }  
  
  //-----------------------
  // End of your first code

  //------------------------
  // Your second code (different timing) starts here

  if (enterFunction2 == true){
    previousTime2= timet;
    tempoativo2inicio= micros();
    //Serial.println(previousTime); // for debugging

    // Start your second code below 
    //-----------------------
    

      if (ledState == false) {
      ledState = true;
      digitalWrite(piscaled, HIGH);
    } else {
      ledState = false;
      digitalWrite(piscaled, LOW);
    }

    tempoativo2final= micros();
    tempototal2 = tempoativo2final - tempoativo2inicio;
  } 
  //-----------------------
  // End of your second code


//------------------------
  // Your third code (different timing) starts here

  if (enterFunction3 == true){
    previousTime3= timet;
    tempoativo3inicio= micros();
    
    // Start your third code below 
    //-----------------------
    
    //Serial.print("Referencia");
    /*Serial.print(percentualreferencia);
    Serial.print(" ");
    //Serial.print("Realimentacao");
    Serial.println(percentualfeedback);*/
    Serial.print("tempo motor= ");
    Serial.print(tempototal1);
    Serial.println(" us");
    Serial.print("tempo LED= ");
    Serial.print(tempototal2);
    Serial.println(" us");
    Serial.print("tempo print= ");
    Serial.print(tempototal3);
    Serial.println(" us");
    tempoativo3final= micros();
    tempototal3 = tempoativo3final - tempoativo3inicio;
  } 
  //-----------------------
  // End of your third code

  
  // The DELAY time is adjusted in the constant below >> 
  if (timet - previousTime < 9999){ // 1 million microsencods= 1 second delay
    /* I have actually used 0.999990 seconds, in a trial to compensate the time that
       this IF function takes to be executed. this is really a point that
       need improvement in my code */   
    enterFunction= false;
  } 
  else {
    enterFunction= true;
  }

  if (timet - previousTime2 < 499999){ // 1 million microsencods= 1 second delay
    /* I have actually used 0.999990 seconds, in a trial to compensate the time that
       this IF function takes to be executed. this is really a point that
       need improvement in my code */   
    enterFunction2= false;
  } 
  else {
    enterFunction2= true;
  }
  
    // The DELAY time is adjusted in the constant below >> 
  if (timet - previousTime3 < 29999){ // 1 million microsencods= 1 second delay
    /* I have actually used 0.999990 seconds, in a trial to compensate the time that
       this IF function takes to be executed. this is really a point that
       need improvement in my code */   
    enterFunction3= false;
  } 
  else {
    enterFunction3= true;
  }

  

}


