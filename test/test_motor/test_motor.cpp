#include "Arduino.h"
#include <unity.h>
#include "ArduinoL289n.h"
#include "ArduinoPotentiometer.h"
#include <string> 



const int motorTest1(7);
const int motorTest2(8);
const int motorTest3(9);

CustomArduino::L289n motorTest(motorTest1,motorTest2,motorTest3);


void setUp(void)
{
  // set stuff up here

}

void tearDown(void)
{
  // clean stuff up here
}

//***Test begin here***//

/*
test generic functions
void SetDir(const bool& direction);
void SetSpeed(const int& dutyCyclePerc);
void DriveFWD();
void DriveBwd();
void DriveFWD(const int& dutyCyclePerc);
void DriveBwd(const int& dutyCyclePerc);
void Brake();
*/
void test_set_speed_fwd(){
    delay(1000);
    int speed(100);
    motorTest.DriveFWD(speed);
    //generic
    TEST_ASSERT_TRUE(motorTest.getStatusIN1());
    TEST_ASSERT_FALSE(motorTest.getStatusIN2());
    TEST_ASSERT_EQUAL(speed,motorTest.getDutyCycle());

    //Custom Arduino
    TEST_ASSERT_EQUAL(1,motorTest.GetIN1PinState());
    TEST_ASSERT_EQUAL(0,motorTest.GetIN2PinState());


}

void test_set_speed_bwd(){
    delay(1000);
    int speed(100);
    motorTest.DriveBWD(speed);
    //generic
    TEST_ASSERT_FALSE(motorTest.getStatusIN1());
    TEST_ASSERT_TRUE(motorTest.getStatusIN2());
    TEST_ASSERT_EQUAL(speed,motorTest.getDutyCycle());

    //Custom Arduino
    TEST_ASSERT_EQUAL(0,motorTest.GetIN1PinState());
    TEST_ASSERT_EQUAL(1,motorTest.GetIN2PinState());

}

void test_set_break(){
    delay(1000);
    motorTest.Brake();
    //generic
    TEST_ASSERT_FALSE(motorTest.getStatusIN1());
    TEST_ASSERT_FALSE(motorTest.getStatusIN2());
    TEST_ASSERT_EQUAL(0,motorTest.getDutyCycle());

    //Custom Arduino
    TEST_ASSERT_EQUAL(0,motorTest.GetIN1PinState());
    TEST_ASSERT_EQUAL(0,motorTest.GetIN2PinState());

}

void test_set_dir(){
    delay(1000);
    motorTest.SetDir(CLOCKWISE);
    TEST_ASSERT_EQUAL(true,motorTest.getStatusIN1());
    TEST_ASSERT_EQUAL(false,motorTest.getStatusIN2());
    motorTest.SetDir(COUNTERCLOCKWISE);
    TEST_ASSERT_EQUAL(false,motorTest.getStatusIN1());
    TEST_ASSERT_EQUAL(true,motorTest.getStatusIN2());

}
//***Tests end here **//
int runUnityTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_set_speed_fwd);
  RUN_TEST(test_set_speed_bwd);
  RUN_TEST(test_set_break);
  RUN_TEST(test_set_dir);
  
  return UNITY_END();
}



void setup()
{
  delay(2000);
  motorTest.SetUp();
  Serial.begin(9600);
  runUnityTests();
}


void loop()
{
}