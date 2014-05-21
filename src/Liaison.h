#ifndef LIAISON_H
#define LIAISON_H

#include "ofMain.h"

class Liaison
{
    public:
        Liaison();
        virtual ~Liaison();
        void setup(int nb);
        void update(ofVboMesh mesh1, ofVboMesh mesh2, ofMatrix4x4 matrix);
        void draw();
    protected:
    private:
        ofVboMesh mesh;
        int nb;
};

#endif // LIAISON_H
