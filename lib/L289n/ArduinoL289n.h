#pragma once
#include "l298n.h"
#include "ArduinoAbstract.h"


namespace CustomArduino{
    class L289n : public Generic::L298n,CustomArduino::ArduinoAbstarct{
    public:
        friend class Generic::L298n;
        using Generic::L298n::L298n;
        void Update()override;
        void SetUp()override;
        void SetDir(const bool& direction);
        void SetSpeed(const int& speed);

    };

};