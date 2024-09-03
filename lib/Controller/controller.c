extern "C" {
	float integrateHistory =0;
	float filterHistory=0;
	float derivativeHistory =0; 

	void FowardsEuler(float * signal, float timestep){
		integrateHistory  = (integrateHistory + signal*timestep);
	}

	void LowPassFilter(float *signal, float alpha){

	}

	void BackwardEuler(float *signal, float alpha, float timestamp){

	}


}	
