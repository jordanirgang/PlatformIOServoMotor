#include "controller.h"


Generic::ErrorModifier::ErrorModifier(const float & gain)
{
    this->k = gain;
    this->history = 0;
}

void Generic::ErrorModifier::UpdateError(float & error)
{
    this->error = error; 
}

float Generic::ErrorModifier::GetHistory()
{
    return this->history;
}
void Generic::ErrorModifier::Step(float& timeStep){
	this->timeStep = timeStep;
}


void Generic::Porportion::operation(float*signalOut,float & error){
    float update(this->k * error * this->timeStep);
    *signalOut += update;
}

void Generic::FowardEuler::operation(float*signalOut,float & error){
    float update(this-> history + this->timeStep * error);
    *signalOut += this->k * update;
    this-> history = update;
}

void Generic::LowPassFilter::operation(float*signalOut,float & signalIn){
    // k is alpha measurement gain, signal in should be the error
    *signalOut = (signalIn* this->k + (1-this->k)* this->history);
    this-> history =  *signalOut;

}

void Generic::BackwardEuler::operation(float*signalOut,float & error){
    this->LPF->operation(signalOut,error);
    this-> history = this->LPF->GetHistory();
    float update( (*signalOut - this->history)/this->timeStep);
    *signalOut += this->k * update;
}





