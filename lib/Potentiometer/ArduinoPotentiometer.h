#pragma once
#include "potentiometer.h"
#include "ArduinoAbstract.h"
namespace CustomArduino{
class Potentiometer: public Generic::Potentiometer, public CustomArduino::ArduinoAbstarct{
    public:
        //Potentiometer(const int &gnd,const int &vcc, const int &data):Generic::Potentiometer(gnd,vcc,data){}
        friend class Generic::Potentiometer::Potentiometer;
        using Generic::Potentiometer::Potentiometer;
        void Update()override;
        void SetUp()override;
};
}
