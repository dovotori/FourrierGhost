#ifndef RAYPICKING_H
#define RAYPICKING_H


#include "Camera.h"
#include "ofMain.h"

class RayPicking
{
    public:
        RayPicking();
        virtual ~RayPicking();
        void update(int x, int y, Camera camera);

        ofVec3f getPositionSurRayon(Camera camera);

    protected:
    private:
        ofVec3f rayon;

};

#endif // RAYPICKING_H
