#pragma once
#include "pingroup.h"

#define CLOCKWISE true
#define COUNTERCLOCKWISE false


namespace Generic{

class L298n
{
private:
    bool dir;
    int maxSpeed;
    int minSpeed;
protected:
    PinGroup<bool> in1;
    PinGroup<bool> in2;
    PinGroup<float> pwmControll;
    int speed;
   
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

};

};