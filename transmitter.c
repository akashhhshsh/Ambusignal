//Transmitter code (STM32F103C8) BLUE PILL:
//433MHZ RF Trasmitter with STM32F103C8
//Transmitter Code

#include <RH_ASK.h>  //RadioHead library

#define buttonPin PB9

byte buttonState = 0;
byte flag = 0;

String transmit = "";

RH_ASK rf_driver(2000, PA9, PA10); //Sets Pin PA9 as receiver and PA10 as transmitterand 2000 as Speed
                                   //Connect data of transmitter to PA10

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  rf_driver.init();
}

void loop()
{
//  buttonState = digitalRead(buttonPin);
//  
//  if(buttonState == LOW && flag == 0)
//  {
//    transmit="a";
//    const char *msg = transmit.c_str();
//    rf_driver.send((uint8_t *)msg, strlen(msg));
//    rf_driver.waitPacketSent();
//    delay(100);
//    flag = 1;
//  }
//  else if(buttonState == LOW && flag == 1)
//  {
//    transmit="b";
//    const char *msg = transmit.c_str();
//    rf_driver.send((uint8_t *)msg, strlen(msg));
//    rf_driver.waitPacketSent();
//    delay(100);
//    flag = 0;
//  }
//  delay(100);

    transmit="a";
    const char *msg = transmit.c_str();
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(100);
}