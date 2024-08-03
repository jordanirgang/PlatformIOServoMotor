#include "ArdunioPotentiometer.h"
#include "Arduino.h"



void CustomArduino::Potentiometer::UpdateData()
{
    this->Generic::Potentiometer::UpdateData(analogRead(this->data.pin));
}

void CustomArduino::Potentiometer::SetUp()
{
    pinMode(this->gnd.pin,OUTPUT);
    pinMode(this->vcc.pin,OUTPUT);
    pinMode(this->data.pin,INPUT);

    digitalWrite(this->gnd.pin,this->gnd.value);
    digitalWrite(this->vcc.pin,this->vcc.value);

}
