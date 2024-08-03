#pragma once
#include "potentiometer.h"
namespace CustomArduino{
class Potentiometer: public Generic::Potentiometer{
    public:
        Potentiometer(const int &gnd,const int &vcc, const int &data):Generic::Potentiometer(gnd,vcc,data){}
        void UpdateData();
        void SetUp();
};
}