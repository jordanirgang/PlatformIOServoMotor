#include "l298n.h"

Generic::L298n::L298n(const int &in1, const int &in2, const int &pwm)
{
    this->in1 = {in1,false};
    this->in2 = {in2,false};
    this->pwmControll= {pwm,0};
    this->maxSpeed= 100;
    this->minSpeed = 0;
}

Generic::L298n::L298n(const int &in1, const int &in2, const int &pwm, const int &maxSpeed, const int &minSpeed)
{
    this->in1 = {in1,false};
    this->in2 = {in2,false};
    this->pwmControll= {pwm,0};
    this->maxSpeed= maxSpeed;
    this->minSpeed = minSpeed;
}

Generic::L298n::~L298n()
{
}

void Generic::L298n::SetDir(const bool& direction)
{
    this->in1.value = direction;
    this->in2.value = !direction;
    this->dir = direction;
}

void Generic::L298n::SetSpeed(const int &dutyCyclePerc)
{

    if (this->minSpeed == 0 && this->maxSpeed == 100){
        this->speed = dutyCyclePerc;
    }else{
        //scale value down
        //initial range between 0 and 100
        //map to min speed and max speed
        int speedRatio = dutyCyclePerc/100;
        //(range_1_max)- (range_1_min))* ratio + range_1_min
        this->speed = (this->maxSpeed - this->minSpeed)*speedRatio+this->minSpeed;
    }

}

void Generic::L298n::DriveFWD()
{
    this->SetDir(CLOCKWISE);
}

void Generic::L298n::DriveBWD()
{
    this->SetDir(COUNTERCLOCKWISE);
}

void Generic::L298n::DriveFWD(const int &speed)
{
    this->SetDir(CLOCKWISE);
    this->SetSpeed(speed);
}

void Generic::L298n::DriveBWD(const int &speed)
{
    this->SetDir(COUNTERCLOCKWISE);
    this->SetSpeed(speed);
}

void Generic::L298n::Brake()
{
    this->in1.value = false;
    this->in2.value = false;
    
    this->SetSpeed(this->minSpeed);
}

bool Generic::L298n::getStatusIN1()
{
    return this->in1.value;
}

bool Generic::L298n::getStatusIN2()
{
    return this->in2.value;
}

int Generic::L298n::getDutyCycle()
{
    return this->speed;
}
