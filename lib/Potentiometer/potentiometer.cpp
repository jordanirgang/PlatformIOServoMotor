#include "potentiometer.h"

Generic::Potentiometer::Potentiometer(const int &data)
{
    this->data = {data,0};
    this->cfgIs3pin=false;
}

Generic::Potentiometer::Potentiometer(const int &gnd, const int &vcc, const int &data)
{
    this->gnd ={gnd,false};
    this->vcc = {vcc,true};
    this->data = {data,0};
    this->cfgIs3pin=true;

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

void Generic::Potentiometer::tune(const int &min, const int &max)
{
    this->trimMin = min;
    this->trimMax = max;
}
//
void Generic::Potentiometer::tunePercent(const int &minPercent, const int &maxPercent)
{
    //feed percents
    this->tune(((minPercent)/100)*this->hardwareMax,((maxPercent)/100)*this->hardwareMax);
}

float Generic::Potentiometer::getPercent()
{

    //float valuePercent = static_cast<float>(this->data.value)/static_cast<float>(this->hardwareMax);
    //max - min * ratio + min
    return static_cast<float>(this->data.value)/static_cast<float>(this->trimMax-this->trimMin)*100;
}
