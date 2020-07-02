
//www.elegoo.com
//2016.12.12

/************************
Exercise the motor using
the L293D chip
************************/
#include <Arduino.h>

#define DIRA 5
#define DIRB 6
#define DIRC 7
#define DIRD 8

#define ENA 9 //右
#define ENB 10 //左

//int receiver = 3;

/*#define A 0xFF629D //16736925
#define B 0xFF22DD //
#define C 0xFFC23D //
#define D 0xFFA857 //16754775
#define E 0xFF02FD //pause
#define f 0xFFA25D //fl0.2
#define G 0xFFE21D //fr0.2
#define H 0xFFE01F //bl0.2
#define I 0xFF906F //br0.2
*/

//IRrecv irrecv(receiver);     // create instance of 'irrecv'
//decode_results results;      // create instance of 'decode_results'

void _mForward()
{ 
      Serial.println("VOL+ forward.");
      analogWrite(ENA,240);
      analogWrite(ENB,255);
      digitalWrite(DIRA,HIGH);
      digitalWrite(DIRB,LOW);
      digitalWrite(DIRC,HIGH);
      digitalWrite(DIRD,LOW);
}
void _mleft()
{
      Serial.println("FAST FORWARD left.");
      analogWrite(ENA,180);
      analogWrite(ENB,180);
      digitalWrite(DIRA,HIGH);
      digitalWrite(DIRB,LOW);
      digitalWrite(DIRC,LOW);
      digitalWrite(DIRD,HIGH);
}
void _mright()
{
      Serial.println("FAST FORWARD right.");
      analogWrite(ENA,180);
      analogWrite(ENB,180);
      digitalWrite(DIRA,LOW);
      digitalWrite(DIRB,HIGH);
      digitalWrite(DIRC,HIGH);
      digitalWrite(DIRD,LOW);
}
void _mBack()
{
      Serial.println("VOL- back.");
      analogWrite(ENA,240);
      analogWrite(ENB,255);
      digitalWrite(DIRA,LOW);
      digitalWrite(DIRB,HIGH);
      digitalWrite(DIRC,LOW);
      digitalWrite(DIRD,HIGH);
}
void _mfleft()
{
      Serial.println("POWER");
      analogWrite(ENA,240);
      analogWrite(ENB,100);
      digitalWrite(DIRA,HIGH);
      digitalWrite(DIRB,LOW);
      digitalWrite(DIRC,HIGH);
      digitalWrite(DIRD,LOW);
}
void _mfright()
{
      Serial.println("FUNC/STOP");
      analogWrite(ENA,100);
      analogWrite(ENB,255);
      digitalWrite(DIRA,HIGH);
      digitalWrite(DIRB,LOW);
      digitalWrite(DIRC,HIGH);
      digitalWrite(DIRD,LOW);

}
void _mbleft()
{
      Serial.println("DOWN");
      analogWrite(ENA,255);
      analogWrite(ENB,100);
      digitalWrite(DIRA,LOW);
      digitalWrite(DIRB,HIGH);
      digitalWrite(DIRC,LOW);
      digitalWrite(DIRD,HIGH);
}
void _mbright()
{
      Serial.println("UP");
      analogWrite(ENA,100);
      analogWrite(ENB,255);
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
  Serial.begin(115200);
  _mStop();
  //irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  //---back and forth example
   char moji;
  if (Serial.available()>0) // have we received an IR signal?
  {
    //RED=results.value;
    //Serial.println(RED); 
    //irrecv.resume(); // receive the next value
    moji = Serial.read(); //char moji = Serial.read()とするとコンパイルでエラー
  }//availableのif文で囲う位置を変えた

  if( moji =='w')
  {
    _mForward();
  }
  else if ( moji =='a')
  {
    _mleft();
    _stepStop();
  }
  else if ( moji =='d')
  {
    _mright();
    _stepStop();
  }
  else if ( moji =='x')
  {
    _mBack();
  }
  else if ( moji =='s')
  {
    _mStop();
  }
  else if ( moji =='q')
  {
    _mfleft();
    delay(200);
    _mForward();    
  }
  else if ( moji =='e')
  {
    _mfright();
    delay(200);
    _mForward();
  }
  else if ( moji =='z')
  {
    _mbleft();
    delay(200);
    _mBack();
  }
  else if ( moji =='c')
  {
    _mbright();
    delay(200);
    _mBack();
  }  
  
}
