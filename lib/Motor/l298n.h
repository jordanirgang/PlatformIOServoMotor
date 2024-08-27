#pragma once
#include "pingroup.h"
#include "motor.h"

#define CLOCKWISE true
#define COUNTERCLOCKWISE false


namespace Generic{

class L298n:Motor
{
private:
    bool dir;
protected:
    PinGroup<bool> in1;
    PinGroup<bool> in2;
    PinGroup<float> pwmControll;
    int frequency;
   
public:
    L298n(const int &in1, const int &in2, const int &pwm);
    L298n(const int &in1, const int &in2, const int &pwm, const int &minSpeed, const int &maxSpeed);

    ~L298n();

    virtual void SetDir(const bool& direction);
    virtual void SetSpeed(const int& dutyCyclePerc);
    void DriveFWD();
    void DriveBWD();
    void DriveFWD(const int& dutyCyclePerc);
    void DriveBWD(const int& dutyCyclePerc);
    void Brake();
    bool getStatusIN1();
    bool getStatusIN2();
    int getDutyCycle();
    void setFrequency(const int& freq);

};

};