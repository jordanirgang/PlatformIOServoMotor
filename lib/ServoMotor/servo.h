#pragma once
#include "potentiometer.h"
#include "motor.h"

namespace Generic{
    class FiveWireServo{
        private:
            float setPoint;
            float currentPoint;
        protected:
            Potentiometer* pot;
            Motor* mot;
        public:
            FiveWireServo( Potentiometer & potentiometerRefrence, Motor & motorRefrence);
            ~FiveWireServo();
            void TurnToPercent(const float & percent);
            float GetError();
            float GetSetpoint();
            float HardReadPotentiometer();

    };
};