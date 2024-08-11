#pragma once
#include "pingroup.h"
namespace Generic{
struct PotentiometerData{
    PinGroup<bool> ground;
    PinGroup<bool> power;
    PinGroup<int> data;
};

class Potentiometer
{
private:
    int trimMin = 0;
    int trimMax = 0;
    bool cfgIs3pin;
protected:
    PinGroup<bool> gnd;
    PinGroup<bool> vcc;
    PinGroup<int> data;  // between 0-4095   
public:
    Potentiometer(const int &data);
    Potentiometer(const int &gnd,const int &vcc, const int &data);
    ~Potentiometer();

    void UpdateData(int dataIn);
    int readData();
};
};

