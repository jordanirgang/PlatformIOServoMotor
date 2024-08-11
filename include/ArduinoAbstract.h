#pragma once
#include "Arduino.h"

namespace CustomArduino{
class ArduinoAbstarct{
public:
    bool debug=false;
    virtual void SetUp() = 0;
    virtual void Update()= 0;
    
};
}