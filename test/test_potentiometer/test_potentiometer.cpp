#include "potentiometer.h"
#include "Arduino.h"
#include <unity.h>
#include "ArduinoPotentiometer.h"
#include "potentiometer.h"
#include <string> 



const int data2read= 100;

const int pot1(2);
const int pot2(2);
const int pot3(1);

CustomArduino::Potentiometer potTest(pot1,pot2,pot3);
//CustomArduino::Potentiometer potBoiArduino(pot1,pot2,pot3);

void setUp(void)
{
  // set stuff up here
  potTest.UpdateData(data2read);
}

void tearDown(void)
{
  // clean stuff up here
}

//TODO: test these Generic functions
//int readData();
//void tune(const int &min,const int &max);
//void tunePercent(const int &minPercent, const int &maxPercent );
//float getPercent();

void test_read_generic_data(){
  TEST_ASSERT_EQUAL(data2read, potTest.readData());
}

void test_get_percent_not_tuned(){
  potTest.UpdateData(4096);
  TEST_ASSERT_EQUAL((float)100, potTest.getPercent());
  potTest.UpdateData(4096/2);
  TEST_ASSERT_EQUAL((float)50, potTest.getPercent());
  potTest.UpdateData(0);
  TEST_ASSERT_EQUAL((float)0, potTest.getPercent());
}

void test_get_percent_tuned(){
  potTest.tune(25,3012);
  potTest.UpdateData(3012);
  TEST_ASSERT_EQUAL((float)100, potTest.getPercent());
  potTest.UpdateData(3012/2);
  TEST_ASSERT_EQUAL((float)50, potTest.getPercent());
  potTest.UpdateData(0);
  TEST_ASSERT_EQUAL((float)0, potTest.getPercent());
}

int runUnityTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_read_generic_data);
  RUN_TEST(test_get_percent_not_tuned);
  RUN_TEST(test_get_percent_tuned);

  return UNITY_END();
}



void setup()
{
  potTest.SetUp();
  potTest.debug = true;
  Serial.begin(9600);
  delay(2000);
  runUnityTests();
}


void loop()
{
}

/*
int main(void) {
  return runUnityTests();
}
*/

