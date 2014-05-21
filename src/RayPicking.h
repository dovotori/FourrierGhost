#ifndef RAYPICKING_H
#define RAYPICKING_H

#include "Vecteur3d.h"
#include "ofMain.h"

class RayPicking
{
    public:
        RayPicking();
        virtual ~RayPicking();
        void setup();
        void draw();
        void update();

    protected:
    private:
        Vecteur3D clickPosInWorld, direction;

};

#endif // RAYPICKING_H
