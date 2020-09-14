#include <Arduino.h>
#include <IRremote.h>
#include <HCSR04.h>

#define A 0xFF629D //16736925 forward
#define B 0xFF22DD //left 
#define C 0xFFC23D //right
#define D 0xFF02FD //pause
#define E 0xFFA25D //lf
#define f 0xFFE21D //lr
int l=6,r=5;
int receiver = 3;
unsigned long RED;

IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void _mForward()
{ 
      Serial.println("VOL+ forward.");
      for (int i = 100; i < 250; i++)
      {
        analogWrite(r,i);
        analogWrite(l,i);
        delay(10);
      }
}
void _mleft()
{
      Serial.println("FAST FORWARD left.");
        analogWrite(r,250);
        analogWrite(l,0);
}
void _mright()
{
      Serial.println("FAST FORWARD right.");
       analogWrite(r,0);
       analogWrite(l,250);
}
void _mfleft()
{
      for (int i = 250; i > 50; i--)
      {
        analogWrite(r,250);
        analogWrite(l,i);
        delay(1);
      }
      delay(400);
      for (int i2 = 50; i2 < 250; i2++)
      {
        analogWrite(r,250);
        analogWrite(l,i2);
        delay(1);
      }     
}

void _mfright()
{
      for (int i = 250; i > 50; i--)
      {
        analogWrite(r,i);
        analogWrite(l,250);
        delay(1);
      }
      delay(400);
      for (int i2 = 50; i2 < 250; i2++)
      {
        analogWrite(r,i2);
        analogWrite(l,250);
        delay(1);
      }     
}
void _mStop()
{
      Serial.println("PAUSE");
      digitalWrite(r,LOW);
      digitalWrite(l,LOW);
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
      //_mstepStop();
      
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
      _mStop();
    }
    else if (RED==E)
    {
      _mfleft();
      //delay(400);
      //_mForward();
      //_mstepStop();
    }
    else if (RED==f)
    {
      _mfright();
      //delay(400);
      //_mForward();
      //_mstepStop();
    }
  }
}