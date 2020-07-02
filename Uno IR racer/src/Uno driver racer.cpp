//www.elegoo.com
//2016.12.12

/************************
Exercise the motor using
the L293D chip
************************/

#include "IRremote.h"

#define DIRA 5
#define DIRB 6
#define DIRC 7
#define DIRD 8

#define ENA 9 //右
#define ENB 10 //左

int receiver = 3;

#define A 0xFF629D //16736925
#define B 0xFF22DD //
#define C 0xFFC23D //
#define D 0xFFA857 //16754775
#define E 0xFF02FD //pause
#define f 0xFFA25D //fl0.2
#define G 0xFFE21D //fr0.2
#define H 0xFFE01F //bl0.2
#define I 0xFF906F //br0.2

unsigned long RED;

IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void _mForward()
{ 
      Serial.println("VOL+ forward.");
      analogWrite(ENA,200);
      analogWrite(ENB,200);
      digitalWrite(DIRA,HIGH);
      digitalWrite(DIRB,LOW);
      digitalWrite(DIRC,HIGH);
      digitalWrite(DIRD,LOW);
}
void _mleft()
{
      Serial.println("FAST FORWARD left.");
      analogWrite(ENA,175);
      analogWrite(ENB,175);
      digitalWrite(DIRA,HIGH);
      digitalWrite(DIRB,LOW);
      digitalWrite(DIRC,LOW);
      digitalWrite(DIRD,HIGH);
}
void _mright()
{
      Serial.println("FAST FORWARD right.");
      analogWrite(ENA,175);
      analogWrite(ENB,175);
      digitalWrite(DIRA,LOW);
      digitalWrite(DIRB,HIGH);
      digitalWrite(DIRC,HIGH);
      digitalWrite(DIRD,LOW);
}
void _mBack()
{
      Serial.println("VOL- back.");
      analogWrite(ENA,200);
      analogWrite(ENB,200);
      digitalWrite(DIRA,LOW);
      digitalWrite(DIRB,HIGH);
      digitalWrite(DIRC,LOW);
      digitalWrite(DIRD,HIGH);
}
void _mfleft()
{
      Serial.println("POWER");
      analogWrite(ENA,175);
      analogWrite(ENB,50);
      digitalWrite(DIRA,HIGH);
      digitalWrite(DIRB,LOW);
      digitalWrite(DIRC,HIGH);
      digitalWrite(DIRD,LOW);
}
void _mfright()
{
      Serial.println("FUNC/STOP");
      analogWrite(ENA,50);
      analogWrite(ENB,175);
      digitalWrite(DIRA,HIGH);
      digitalWrite(DIRB,LOW);
      digitalWrite(DIRC,HIGH);
      digitalWrite(DIRD,LOW);

}
void _mbleft()
{
      Serial.println("DOWN");
      analogWrite(ENA,175);
      analogWrite(ENB,50);
      digitalWrite(DIRA,LOW);
      digitalWrite(DIRB,HIGH);
      digitalWrite(DIRC,LOW);
      digitalWrite(DIRD,HIGH);
}
void _mbright()
{
      Serial.println("UP");
      analogWrite(ENA,50);
      analogWrite(ENB,175);
      digitalWrite(DIRA,LOW);
      digitalWrite(DIRB,HIGH);
      digitalWrite(DIRC,LOW);
      digitalWrite(DIRD,HIGH);
}
void _mStop()
{
      Serial.println("PAUSE");
      analogWrite(ENA,LOW);
      analogWrite(ENB,LOW);
}

void _stepStop()
{
  delay(500);
  _mStop();
}

void setup() {
  //---set pin direction
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(DIRC,OUTPUT);
  pinMode(DIRD,OUTPUT);
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

    if(RED==A)
    {
      _mForward();
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
    }
    else if (RED==E)
    {
      _mStop();
    }
    else if (RED==f)
    {
        _mfleft();
        delay(200);
      _mForward();
      
    }
    else if (RED==G)
    {
      _mfright();
      delay(200);
      _mForward();
    }
    else if (RED==H)
    {
      _mbleft();
      delay(200);
      _mBack();
    }
    else if (RED==I)
    {
      _mbright();
      delay(200);
      _mBack();
    }
 }  
  
}
