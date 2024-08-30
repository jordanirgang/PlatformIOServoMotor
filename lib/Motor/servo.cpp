#include "servo.h"
#include "potentiometer.h"
#include "motor.h"

   

Generic::FiveWireServo::FiveWireServo(Generic::Potentiometer & potentiometerRefrence, Generic::Motor & motorRefrence)
{
   this->pot = &potentiometerRefrence;
   this->mot = &motorRefrence;
}

Generic::FiveWireServo::~FiveWireServo()
{
   delete pot;
   delete mot;
}


void Generic::FiveWireServo::TurnToPercent(const float & percent)
{
   this->setPoint = percent;
}

float Generic::FiveWireServo::GetError()
{
   float error(0);
   error = this->GetSetpoint() - this->HardReadPotentiometer();
   //
   return error;
}

float Generic::FiveWireServo::GetSetpoint()
{
    return this->setPoint;
}

float Generic::FiveWireServo::HardReadPotentiometer()
{
   return static_cast<float>(this->pot->readData());
}
