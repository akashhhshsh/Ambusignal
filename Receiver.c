//BLACK PILL RECEIVER
//Receiver Code
//433MHZ RF with STM32F103C8 as Transmitter

#include <RH_ASK.h>  //Includes RadioHead Library

#define greenLed 9
#define redLed 10

String str_receive;                 //Strings to Store Value
RH_ASK rf;                          //rf as object for RG_ASK

int counter = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  rf.init();                     //Initialize rf Object
}

void loop()
{
  uint8_t buf[7];                       
  uint8_t buflen = sizeof(buf);
  Serial.println(buf[7]);
  if (rf.recv(buf, &buflen))                                  
  {
    str_receive = String((char*)buf);                          // Receive String from the Transmitter
    Serial.println(str_receive);

    if(str_receive[0] == 'a')
    {  
     digitalWrite(greenLed, HIGH);
     digitalWrite(redLed, LOW);
    }  
//    else if(str_receive[0] == 'b')
//    {
//     digitalWrite(redLed, HIGH);
//     digitalWrite(greenLed, LOW);
//    }
  }
    else
    {
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
    }
    delay(500);
}