#ifndef EFFET_H
#define EFFET_H

#include "ofMain.h"

class Effet
{
    public:
        Effet();
        virtual ~Effet();
        void setup();
        void begin();
        void end();
        void draw();
    protected:
    private:
        ofFbo renderBuffer;
        ofShader shader;
};

#endif // EFFET_H
