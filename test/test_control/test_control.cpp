#include "unity.h"
#include "controller.h"
#include <iostream>


#define Kp .02
#define Ki .02
#define Kd .002
#define Kalpha .998
using namespace Generic;


void setUp(){

}

void tearDown(){

}
/*
 *:
*ErrorModifier(const float & gain);
*virtual void operation(float*signalOut,float & error){}
*void UpdateError(float & error);
*float GetHistory();	z	
*void Step(float & timeStep);
};
 *
 *
 Porportion(const float & gain)
 FowardEuler(const float & gain)
 BackwardEuler(const float & gain,const float & measureGain)
 LowPassFilter(const float & measureGain)

 */
Porportion porportion(Kp);
FowardEuler integral(Ki);
BackwardEuler derivative(Kd,Kalpha);

float testController(ErrorModifier &control, const int & maxSteps,const float & setPoint){
	float * currPoint = new float(0);
	float diff =  *currPoint-setPoint;
	TEST_ASSERT_EQUAL(setPoint,- diff);
	//debug only, comment out
	//TEST_ASSERT_EQUAL(setPoint,*currPoint);
	for (int i = 0; i <= maxSteps; i++){
		diff = setPoint - *currPoint;
		control.Step(.1); 
		control.operation(currPoint,diff);
		std::cout << *currPoint << "\n";

	}
	delete currPoint;
	//debug only, comment out
	return diff;

}
void testPorportion(){
	int diff =testController(porportion,1000,100);
	TEST_ASSERT_FLOAT_WITHIN(.5, 0, diff);
}

void testIntegral(){
	int diff = testController( integral, 1000,100);
	TEST_ASSERT_FLOAT_WITHIN(.5, 0, diff);
}
void testDerivative(){
	int setPoint(100);
	int diff = testController(derivative,10,setPoint);
	std::cout<< diff;
	TEST_ASSERT_FLOAT_WITHIN(.5, 0, diff);

	//TODO verify setpoint is correct
}

void testPID(){
	int maxSteps(80);
	float setPoint(100);
	float* currPoint= new float(0);
	float diff;
	integral.WipeHistory();
	porportion.WipeHistory();
	derivative.WipeHistory();
	for(int i = 0; i< maxSteps;i++){
		diff = setPoint -*currPoint;
		integral.Step(1);
		porportion.Step(1);
		derivative.Step(1);

		porportion.operation(currPoint,diff);
		integral.operation(currPoint,diff);
		derivative.operation(currPoint,diff);
		std::cout << *currPoint << "\n";
		
	}
	diff = setPoint-*currPoint;
	delete currPoint;

	TEST_ASSERT_FLOAT_WITHIN(.5, 0,diff);

}

int runUnityTests(void) {
	  UNITY_BEGIN();
	    //RUN_TEST(testPorportion);
	    //RUN_TEST(testIntegral);
	    //RUN_TEST(testDerivative);
	    RUN_TEST(testPID);
	      return UNITY_END();
}

int main(){
	    runUnityTests();
	        return 0;
}
