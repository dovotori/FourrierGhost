#ifndef ATTRACTOR_H
#define ATTRACTOR_H

#include "Node.h"

class Attractor
{
    public:
        Attractor();
        virtual ~Attractor();
        void setup(float x = 0, float y = 0, float z = 0);
        void attract(Node *node);

        inline void setPosition(float x = 0, float y = 0, float z = 0){ this->position.set(x, y, z); };
        inline void setStrength(float value){ this->strength = value; };
        inline void setRadius(float value){ this->radius = value; };

    protected:
    private:
        ofVec3f position;
        float radius;
        float strength; // positive attraction, negative repulsion
        float ramp;     // force elastique 0.01 - 0.99
};

#endif // ATTRACTOR_H
