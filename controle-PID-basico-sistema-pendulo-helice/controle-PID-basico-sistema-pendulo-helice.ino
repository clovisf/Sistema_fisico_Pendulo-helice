/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>

#define PIN_INPUT A2
#define PIN_OUTPUT 9


//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=1.5, Ki=1.5, Kd=0.0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

unsigned long timet;
unsigned long previousTime;
boolean enterFunction= true;

void setup()
{
  Serial.begin(115200);
  //initialize the variables we're linked to
  Input = analogRead(PIN_INPUT);
  Setpoint = analogRead(A1);

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
  Input = map(analogRead(PIN_INPUT),387,650,0,100);
  Setpoint = map(analogRead(A1),0,1023,0,100);
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);


// A partir daqui fica apenas o código da comunicação serial!

  timet = micros();
  if (enterFunction == true){
    previousTime= timet;
    
    // Start your first code below 
    //-----------------------

    Serial.print(Setpoint);      //the first variable for plotting
    Serial.print(" ");              //seperator
    Serial.println(Input);  
  
    //-----------------------
    // End of your first code
  }
// The DELAY time is adjusted in the constant below >> 
  if (timet - previousTime < 99999){ // 1 million microsencods= 1 second delay
    /* I have actually used 0.999990 seconds, in a trial to compensate the time that
       this IF function takes to be executed. this is really a point that
       need improvement in my code */   
    enterFunction= false;
  } 
  else {
    enterFunction= true;
  }
}


