#include <Arduino.h>
#include "ArdunioPotentiometer.h"
using namespace CustomArduino;

const int pinLED(LED_BUILTIN);

const int pot1(7);
const int pot2(8);
const int pot3(9);



Potentiometer potBoi(pot1,pot2,pot3);
//0 is ground
//1 is power
//2 is data
// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED,OUTPUT);
  potBoi.SetUp();
  Serial.begin(9600);

  //TODO:Add motor driver setup
}

void loop() {
  //digitalWrite(pinLED,HIGH);
  //Serial.println("high");
  potBoi.UpdateData();
  //Serial.println(potBoi.readData());
  Serial.println(analogRead(pot3));  //digitalWrite(pinLED,LOW);
  //Serial.println("Low");
  delay(125);

  //TODO:Add motor driver write
}
