#include <Arduino.h>
#include "ArduinoPotentiometer.h"
#include "ArduinoL289n.h"

using namespace CustomArduino;

const int pinLED(LED_BUILTIN);

const int pot1(2);
const int pot2(2);
const int pot3(1);

const int motor1(7);
const int motor2(8);
const int motor3(9);



Potentiometer potBoi(pot1,pot2,pot3);
L289n motorDriver(motor1,motor2,motor3,0,255);
//0 is ground
//1 is power
//2 is data
// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  potBoi.SetUp();
  potBoi.debug = true;
  Serial.begin(9600);
  motorDriver.SetUp();
  //TODO:Add motor driver setup
}

void loop() {

  potBoi.Update();
  delay(125);
  motorDriver.DriveFWD(80);
  delay(1000);
  motorDriver.Brake();
  delay(1000);

  motorDriver.DriveBwd(80);
  delay(1000);

  motorDriver.Brake();
  delay(1000);


  //TODO:Add motor driver write
}
