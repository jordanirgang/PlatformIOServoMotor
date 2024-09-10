#include "unity.h"
void setUp(){

}

void tearDown(){

}
void get_setpoint_diff(){
	TEST_ASSERT_EQUAL(1,1);
}

int runUnityTests(void) {
	  UNITY_BEGIN();
	    RUN_TEST(get_setpoint_diff);
	      return UNITY_END();
}

int main(){
	    runUnityTests();
	        return 0;
}
