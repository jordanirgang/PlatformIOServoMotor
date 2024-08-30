#pragma once

namespace Generic{
class  Motor{
    protected:
        int speed;
        int maxSpeed;
        int minSpeed;
    public:
        virtual void SetDir(const bool& direction){}
        virtual void SetSpeed(const int& dutyCyclePerc){}
        virtual void DriveFWD() {}
        virtual void DriveBWD(){}
        virtual void DriveFWD(const int& dutyCyclePerc){}
        virtual void DriveBWD(const int& dutyCyclePerc){}
        virtual void Brake(){}
};
};

