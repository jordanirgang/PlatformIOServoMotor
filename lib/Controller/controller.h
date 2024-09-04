#pragma once

float time_step(0);


namespace Generic{
    class ErrorModifier{
        private:
            float error;
        protected:
            float k;
            float history;
        public:
            ErrorModifier(const float & gain);
            virtual void operation(float*signalOut,float & error){}
            void UpdateError(float & error);
            float GetHistory();
    };

    class Porportion: public ErrorModifier{
         public:
            Porportion(const float & gain):ErrorModifier(gain){}
            void operation(float*signalOut,float & error);
    };

    class FowardEuler: public ErrorModifier{
         public:
            FowardEuler(const float & gain):ErrorModifier(gain){}
            void operation(float*signalOut,float & error);
    };

    class LowPassFilter: public ErrorModifier{
        protected:
            float alpha;
        public:
            LowPassFilter(const float & measureGain):ErrorModifier(measureGain){this->k = measureGain;}
            void operation(float*signalOut,float & signalIn);
    };

    class BackwardEuler: public ErrorModifier{
        private:
            LowPassFilter* LPF;
        public:
            BackwardEuler(const float & gain,const float & measureGain):ErrorModifier(gain){this->LPF = new LowPassFilter(measureGain);}
            void operation(float*signalOut,float & error);

    };

};