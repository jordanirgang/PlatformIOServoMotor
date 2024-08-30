#include <unity.h>                                                                                                                                                           
#include "servo.h"    
#include "ArduinoL289n.h"
#include "ArduinoPotentiometer.h"

#include <string> 

const int data2read= 100;

const int pot1(2);
const int pot2(2);
const int pot3(1);

CustomArduino::Potentiometer potTest(pot1,pot2,pot3);


const int motorTest1(7);
const int motorTest2(8);
const int motorTest3(9);

CustomArduino::L289n motorTest(motorTest1,motorTest2,motorTest3);

Generic::FiveWireServo servoTest(potTest,motorTest);

void setUp(void)
{
  // set stuff up here
  potTest.UpdateData(data2read);
}

void tearDown(void)
{
  // clean stuff up here
}


void get_setpoint_diff(){

    servoTest.TurnToPercent(0);
    TEST_ASSERT_EQUAL(100,servoTest.HardReadPotentiometer());
    //setpoint is 0, potentiometer is 100, so should return an error of -100
    TEST_ASSERT_EQUAL(-data2read, servoTest.GetError());
    servoTest.TurnToPercent(2*data2read);
    TEST_ASSERT_EQUAL(data2read, servoTest.GetError());
    servoTest.TurnToPercent(data2read/2);
    TEST_ASSERT_EQUAL(-data2read/2, servoTest.GetError());
    servoTest.TurnToPercent(data2read);
    TEST_ASSERT_EQUAL(0, servoTest.GetError());

    potTest.UpdateData(0);
    TEST_ASSERT_EQUAL(0,servoTest.HardReadPotentiometer());
    TEST_ASSERT_EQUAL(data2read, servoTest.GetError());

}


int runUnityTests(void) {
  UNITY_BEGIN();
  RUN_TEST(get_setpoint_diff);
  return UNITY_END();
}


void setup()
{
  delay(2000);
  motorTest.SetUp();
  potTest.SetUp();
  potTest.UpdateData(data2read);

  
  Serial.begin(9600);
  runUnityTests();
}


void loop()
{
}

/*
int main(){
    runUnityTests();
    return 0;
}
*/


