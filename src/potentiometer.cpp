#include "potentiometer.h"

Generic::Potentiometer::Potentiometer(const int &gnd,const int &vcc, const int &data)
{
    this->gnd ={gnd,false};
    this->vcc = {vcc,true};
    this->data = {data,0};
}

Generic::Potentiometer::~Potentiometer()
{
}

void Generic::Potentiometer::UpdateData(int dataIn)
{
    this->data.value = dataIn;
}

int Generic::Potentiometer::readData()
{
    return this->data.value;
}
