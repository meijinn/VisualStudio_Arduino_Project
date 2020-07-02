/*#include <Arduino.h>

void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);take2
}

void loop() {take1
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  delay(1000);
}*/

  /*if(RED==A)
    {
      _mForward();
      _stepStop();
    }
    else if (RED==B)
    {
      _mleft();
      _stepStop();
    }
    else if (RED==C)
    {
      _mright();
      _stepStop();
    }
    else if (RED==D)
    {
      _mBack();
      _stepStop();
    }
  }*///take3

#include "IRremote.h"//take4

#define A 0xFF629D //16736925 forward
#define B 0xFF22DD //left 
#define C 0xFFC23D //right
#define D 0xFF02FD //pause
#define E 0xFFA25D //lf
#define f 0xFFE21D //lr
int l=5,r=6;
int receiver = 3;
unsigned long RED;

int LED = 17;

IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void _mForward()
{ 
      Serial.println("VOL+ forward.");
       digitalWrite(l,HIGH);
       digitalWrite(r,HIGH);
       delay(500);
}
void _mleft()
{
      Serial.println("FAST FORWARD left.");
       digitalWrite(l,HIGH);
       digitalWrite(r,LOW);
}
void _mright()
{
      Serial.println("FAST FORWARD right.");
       digitalWrite(l,LOW);
       digitalWrite(r,HIGH);
}
void _mStop()
{
      Serial.println("PAUSE");
      digitalWrite(l,LOW);
      digitalWrite(r,LOW);
}
void _mstepStop()
{
      delay(250);
      _mStop();
}

void setup() {
  //---set pin direction
  pinMode(l,OUTPUT);
  pinMode(r,OUTPUT);
  Serial.begin(9600);
  _mStop();
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  //---back and forth example
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    RED=results.value;
    Serial.println(RED); 
    irrecv.resume(); // receive the next value
    delay(150);

    if (RED==A)
    {
      _mForward();
      _mstepStop();
      
    }
    else if (RED==B)
    {
      _mleft();
      _mstepStop();
    }
    else if (RED==C)
    {
      _mright();
      _mstepStop();
    }
    else if (RED==D)
    {
      _mstepStop();
    }
    else if (RED==E)
    {
      _mleft();
      delay(200);
      _mForward();
      _mstepStop();
    }
    else if (RED==f)
    {
      _mright();
      delay(200);
      _mForward();
      _mstepStop();
    }
    

    /*switch (RED) take 5
    {
    case A:
      _mForward();
      delay(10000);
      _mstepStop();
      break;
    case B:
      _mleft();
      _mstepStop();
      break;
    case C:
      _mright();
      _mstepStop();
      break;
    case D:
      _mstepStop();
      break;
    default:
      break;
    }*/

  }
}
