#pragma once
#include "pingroup.h"
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
    L298n(const int &in1, const int &in2, const int &pwm, const int &maxSpeed, const int &minSpeed);

    ~L298n();

    void SetDir(const bool& direction);
    void SetSpeed(const int& dutyCyclePerc);
    void DriveFWD();
    void DriveBwd();
    void DriveFWD(const int& dutyCyclePerc);
    void DriveBwd(const int& dutyCyclePerc);
    void Brake();
};

};