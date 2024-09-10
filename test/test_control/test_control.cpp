#include "unity.h"
#include "controller.h"


#define Kp .1
#define Ki 10
#define Kd 10
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
*float GetHistory();
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

void testController(ErrorModifier &control, const int & maxSteps){
	float setPoint(100);
	float * currPoint = new float(0);
	float diff =  *currPoint-setPoint;
	TEST_ASSERT_EQUAL(setPoint,- diff);
	//debug only, comment out
	//TEST_ASSERT_EQUAL(setPoint,*currPoint);
	for (int i = 0; i <= maxSteps; i++){
		diff = setPoint - *currPoint;
		control.Step(.1); 
		control.operation(currPoint,diff);
	}
	bool isFound = (diff) <= .5 && (diff) >= - .5;
	delete currPoint;
	//debug only, comment out
	TEST_ASSERT_FLOAT_WITHIN(.5, 0, diff);

	TEST_ASSERT_TRUE(isFound);

}
void testPorportion(){
	testController(porportion,1000);
}

void testIntegral(){
	testController( integral, 1000);
}

int runUnityTests(void) {
	  UNITY_BEGIN();
	    RUN_TEST(testPorportion);
	    RUN_TEST(testIntegral);
	      return UNITY_END();
}

int main(){
	    runUnityTests();
	        return 0;
}
