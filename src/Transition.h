#ifndef TRANSITION_H
#define TRANSITION_H


class Transition
{
    public:
        Transition();
        virtual ~Transition();
        void setup(float origine = 0.0, float destination = 1.0, unsigned int duration = 1);
        float update();

        static inline float lerp(float t, float a, float b){ return (1-t)*a + t*b; };
        inline bool isFinished(){ return this->isFinish; };

    protected:
    private:
        float cpt;
        bool isFinish;
        unsigned int duration;
        float origine, destination;

        float linearTween(float t, float b, float c, unsigned int d);

};

#endif // Transition_H
