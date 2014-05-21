#ifndef FORME_H
#define FORME_H

#include "ofMain.h"
#include "Loadobj.h"


class Forme
{
    public:
        Forme();
        virtual ~Forme();
        void setup();
        void update();
        void draw();
        void interaction(int sens);

        void setPosition(float x, float y, float z);
        void setSize(float w, float h, float d);
        void setSpeed(float s);

        inline ofVboMesh getMesh(){ return this->mesh; };
        inline ofMatrix4x4 getModelMatrix(){ return Forme::model; };

        static void common();

    protected:
    private:

        static ofMatrix4x4 model, view, projection;

        static ofShader shader;
        static ofVboMesh mesh;

        float x, y, z, w, h, d, s;
        float rotationY;


};

#endif // FORME_H
