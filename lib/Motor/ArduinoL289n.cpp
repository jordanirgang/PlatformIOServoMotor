#include "ArduinoL289n.h"

void CustomArduino::L289n::Update()
{
    if(this->debug){
        Serial.print("writing pwm dignal at");
        Serial.println(this->pwmControll.value);
    }
}

void CustomArduino::L289n::SetUp()
{
    pinMode(this->in1.pin,OUTPUT);
    pinMode(this->in2.pin,OUTPUT);
    pinMode(this->pwmControll.pin,INPUT);
    this->setFrequency(10000);
    //digitalWrite(this->in.pin,this->gnd.value);
    //digitalWrite(this->vcc.pin,this->vcc.value);
}

void CustomArduino::L289n::SetDir(const bool &direction)
{
    Generic::L298n::SetDir(direction);
    digitalWrite(this->in1.pin,this->in1.value);
    digitalWrite(this->in2.pin,this->in2.value);
}

void CustomArduino::L289n::SetSpeed(const int &dutyCyclePerc)
{
    Generic::L298n::SetSpeed(dutyCyclePerc);
    if(dutyCyclePerc == 0 ){
        //handlebrake
        digitalWrite(this->in1.pin,this->in1.value);
        digitalWrite(this->in2.pin,this->in2.value);
    }else{
        pwm(this->pwmControll.pin,10000,this->pwmControll.value);
    }
    
}

int CustomArduino::L289n::GetIN1PinState()
{
    return digitalRead(this->in1.pin);

}

int CustomArduino::L289n::GetIN2PinState()
{
    return digitalRead(this->in2.pin);
}
