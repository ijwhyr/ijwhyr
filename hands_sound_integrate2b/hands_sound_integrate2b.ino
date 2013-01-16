/***************************
by Ellen Keith, Yael Braha, Mark Roth, Tosh Chiang and Jasdeep Garcha
for SF UP festival 2012
***********************/


#include "pitches.h"


///audio
int melody[] = { 
  NOTE_E5, NOTE_B6};
int melody2[] = { 
  NOTE_F5, NOTE_C6};
int noteDurations[] = {
  8, 8, 2};

//sampling and io
int pairOne = A0;
int pairTwo = A1;
int led = 13;
int aOut = 12;

//the rest

int triggerThresh = 50; //sets the trigger foroutput
boolean stopMusic = true;
int countOut = 0;

void setup() { //configures inputs and outputs

  Serial.begin(9600);
  pinMode(pairOne, INPUT);
  pinMode(pairTwo, INPUT);
  pinMode(led, OUTPUT);   //on arduino
  pinMode(aOut, OUTPUT);  
}


void loop() {
  
  int handShakeReadFinal1;//for final 
  int handShakeReadFinal2;
  analogReference(INTERNAL1V1); //command varies between arduinos
  //  analogReference(INTERNAL);
  // read the input on analog pin 0 and 1:
  int handShakeRead1 = analogRead(pairOne); 
    delay(10); //resample pin 0!
  int handShakeRead1b = analogRead(pairOne); 
  int handShakeRead2 = analogRead(pairTwo);
    delay(10); //resample pin 1!
  int handShakeRead2b = analogRead(pairTwo);
  

//output value only if both samples are greater than threshold and non-zero 
if (handShakeRead1 > triggerThresh and handShakeRead1b > triggerThresh){
   handShakeReadFinal1 = handShakeRead1;
  }
  else
  {
    handShakeReadFinal1 = 0; 
  }
 
  
if (handShakeRead2 > triggerThresh and handShakeRead2b > triggerThresh){
   handShakeReadFinal2 = handShakeRead2;
  }
  else
  {
    handShakeReadFinal2 = 0;
  }

//print values to serial port
  Serial.print('A');
  Serial.println(handShakeReadFinal1);
  Serial.print('B');
  Serial.println(handShakeReadFinal2);


 // delay(50);    

//audio 

if(handShakeReadFinal1>triggerThresh || handShakeReadFinal2>triggerThresh)
  {
    digitalWrite(led, HIGH);
    if (stopMusic) {
      tune();
    }
  }
  else
  {
    countOut = 0;
    stopMusic = true;
    digitalWrite(led, LOW);
    //delay(1000);  
  } 
}


void tune(){
  for (int thisNote = 0; thisNote < 2; thisNote++) {
    int noteDuration = 1000/noteDurations[thisNote];
    tone(aOut, melody[thisNote], noteDuration);
    delay(noteDuration +30);
  }  
  stopMusic=false;
}

