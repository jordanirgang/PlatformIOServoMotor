#include "ArduinoPotentiometer.h"


void CustomArduino::Potentiometer::Update()
{
    this->Generic::Potentiometer::UpdateData(analogRead(this->data.pin));
    if(this->debug){
        Serial.println(this->getPercent());
    }
}

void CustomArduino::Potentiometer::SetUp()
{
   
    pinMode(this->data.pin,INPUT);
    if(this->cfgIs3pin){
        pinMode(this->gnd.pin,OUTPUT);
        pinMode(this->vcc.pin,OUTPUT);
        digitalWrite(this->gnd.pin,this->gnd.value);
        digitalWrite(this->vcc.pin,this->vcc.value);
    }
    this->hardwareMax = 4095;
    this->tune(0,this->hardwareMax);
}
