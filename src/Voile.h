#ifndef VOILE_H
#define VOILE_H

#include "ofMain.h"
#include "ofxTimer.h"
#include "Loadobj.h"

class Voile
{
    public:
        Voile();
        virtual ~Voile();
        void setup();
        void update();
        void draw();
        void interaction(int key);
    protected:
    private:
        ofMesh screen;
        ofShader shader;
        float cpt, opacity;
        ofxTimer timer;
};

#endif // VOILE_H
