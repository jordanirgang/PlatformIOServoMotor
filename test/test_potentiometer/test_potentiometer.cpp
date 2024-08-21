#include "potentiometer.h"
#include "Arduino.h"
#include <unity.h>
//#include "ArduinoPotentiometer.h"
#include "potentiometer.h"


const int data2read= 100;

const int pot1(2);
const int pot2(2);
const int pot3(1);

Generic::Potentiometer potTest(pot1,pot2,pot3);
//CustomArduino::Potentiometer potBoiArduino(pot1,pot2,pot3);

void setUp(void)
{
  // set stuff up here
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

int runUnityTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_read_generic_data);
  return UNITY_END();
}



void setup()
{
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

