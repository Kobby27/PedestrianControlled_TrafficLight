#include <Arduino.h>
#include "lcd.h"
/*

Traffic light system by Steve Anderson. I started this mini 
project on 01/08/2026 to teach young aspiring engineers useful electronics skills.

This was made to mimic the pedestrian controlled crossings 
in Southampton inspired by my time as a student at the University of Southampton on 
bi-directional roads (Highfield Road) that don't have a lot of pedestrians, hence
the traffic lights stay green until a pedestrian presses the button to cross. 

The logic is therefore not as complicated as traffic lights at a T-junction for example but this is 
a good challenge to revise on embedded programming, circuit design etc

*/


const int Red_LED = 23;
const int Yellow_LED = 2;
const int Green_LED = 5;

const int Button = 15;
const int Buzzer = 4;
const int PedRed_LED = 19;
const int PedGreen_LED = 18;

void greenState()
{

  digitalWrite(Green_LED, HIGH);
  digitalWrite(Yellow_LED, LOW);
  digitalWrite(Red_LED, LOW);
  digitalWrite(PedRed_LED, HIGH);
  digitalWrite(PedGreen_LED, LOW);
}

void setup()
{
  Serial.begin(115200);

  
  pinMode(Button, INPUT_PULLUP);
  pinMode(Red_LED, OUTPUT);
  pinMode(Yellow_LED, OUTPUT);
  pinMode(Green_LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(PedGreen_LED, OUTPUT);
  pinMode(PedRed_LED, OUTPUT);

  greenState(); // default state - Traffic light is green
  lcdSetup();
}

void goAgain()
{
  //digitalWrite(PedRed_LED, LOW);
 // digitalWrite(PedGreen_LED, HIGH);
  digitalWrite(Red_LED, HIGH);
  delay(500);


  digitalWrite(PedGreen_LED, LOW);
  digitalWrite(Red_LED, LOW);
  digitalWrite(Yellow_LED, HIGH);
  digitalWrite(PedRed_LED, HIGH);
  delay(1000);

   digitalWrite(Green_LED, HIGH);

  delay(2000);
  digitalWrite(Yellow_LED, LOW);
}

void stopGoing()
{
  digitalWrite(PedGreen_LED, LOW);
  digitalWrite(PedRed_LED, HIGH);
  digitalWrite(Green_LED, HIGH);
  delay(2500);

  digitalWrite(Green_LED, LOW);
  digitalWrite(Yellow_LED, HIGH);
  delay(2500);

  digitalWrite(Yellow_LED, LOW);
  digitalWrite(Red_LED, HIGH);
  digitalWrite(PedGreen_LED, HIGH);
  digitalWrite(PedRed_LED, LOW);
}


void soundBuzzer()
{

  digitalWrite(Buzzer, HIGH);
  delay(50);
  digitalWrite(Buzzer, LOW);
  delay(50);
  digitalWrite(Buzzer, HIGH);
  delay(50);
  digitalWrite(Buzzer, LOW);
  delay(50);
  digitalWrite(Buzzer, HIGH);
  
  delay(50);
  digitalWrite(Buzzer, LOW);

  delay(50);
  digitalWrite(Buzzer, HIGH);

  delay(50);
  digitalWrite(Buzzer, LOW);
  delay(50);
  digitalWrite(Buzzer, HIGH);

  delay(500);
  digitalWrite(Buzzer, LOW);
}

// pedestrian crossing sequence when the button is pressed
void PedestrianCross()
{

  stopGoing();
  delay(1000);

  soundBuzzer();
  if (PedCount()){
    digitalWrite(PedGreen_LED, LOW);
    digitalWrite(PedRed_LED, HIGH);
  }
  delay(1800);

  goAgain();
}



//when the button is pressed, the pedestrian crossing sequence begins
void loop() {
if (digitalRead(Button) == LOW){
  PedestrianCross();
  }
}
  
  
