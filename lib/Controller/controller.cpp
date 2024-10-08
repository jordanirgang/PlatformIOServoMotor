#include "controller.h"
//TODO: delete this
#include <iostream>


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
void Generic::ErrorModifier::Step(float timeStep){
	this->timeStep = timeStep;
}

void Generic::ErrorModifier::WipeHistory(){
	this->history = 0;
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
    //TODO: delete this
    //std::cout << "Low pass Filter" <<signalIn<<"in:out"<<this->history<<"\n";//* this->k;

            //global filter_history
            //filter_history = filter_history*alpha_gain + (1- alpha_gain) * update

            //backup_history = filter_history
            //filtered_update = LowPassFilter(update,alpha_gain)
            //return (filtered_update-backup_history)/time_step

        this-> history  = (signalIn) * this->k + (1-this->k)* this->history;

        }

void Generic::BackwardEuler::operation(float*signalOut,float & error){
    //this-> history = this->LPF->GetHistory();

    float backup_history(this->GetHistory());
    //std::cout << "hostory"<< backup_history<< "\n";

    //std::cout << "lpf in"<< this->LPF->GetHistory() << "\n";
    this->LPF->operation(signalOut, error); //filtered update
    
    //std::cout << "lpf out"<< this->LPF->GetHistory()<< "\n";

    float update( (this->LPF->GetHistory() - this->history)/this->timeStep);
    std::cout << "Backward Euler" << *signalOut << " + " << this->k << "*" << update << "\n";
    this-> history = update;
    *signalOut += this->k * update;
}





