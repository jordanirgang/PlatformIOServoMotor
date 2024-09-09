#include <unity.h>
void setup(){

}

void teardown(){

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
