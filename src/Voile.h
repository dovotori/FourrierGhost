#ifndef VOILE_H
#define VOILE_H

#include "ofMain.h"
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

        inline void setOpacity(float value){ this->shader.begin(); this->shader.setUniform1f("opacity", value); this->shader.end(); };

    protected:
    private:
        ofMesh screen;
        ofShader shader;
};

#endif // VOILE_H
