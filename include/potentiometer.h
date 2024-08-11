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
    int trimMax = 100;

protected:
    PinGroup<bool> gnd;
    PinGroup<bool> vcc;
    PinGroup<int> data;  // between 0-4095   
    bool cfgIs3pin;
    int hardwareMax = 100;

public:
    Potentiometer(const int &data);
    Potentiometer(const int &gnd,const int &vcc, const int &data);
    ~Potentiometer();

    void UpdateData(int dataIn);
    int readData();
    void tune(const int &min,const int &max);
    void tunePercent(const int &minPercent, const int &maxPercent );
    float getPercent();// float for higher percent accuracy(potentiometers will typically be read in int)
};
};

