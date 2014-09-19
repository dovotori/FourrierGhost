#ifndef FORME_H
#define FORME_H

#include "ofMain.h"
#include "Loadobj.h"
#include "Camera.h"


class Forme
{
    public:
        Forme();
        virtual ~Forme();
        void setup();
        void update();
        void draw(Camera *camera);
        void interaction();

        inline void setPosition(float x, float y, float z){  this->x = x; this->y = y; this->z = z; };
        inline void setSize(float w, float h, float d){ this->w = w; this->h = h; this->d = d; };
        inline void setSpeed(float s){ this->s = s; };
        inline void setColor(float r, float v, float b) { Forme::shader.begin(); Forme::shader.setUniform3f("color", r/255.0, v/255.0, b/255.0); Forme::shader.end(); }

        inline ofVboMesh* getMesh(){ return &this->mesh; };
        inline ofMatrix4x4 getModelMatrix(){ return Forme::model; };
        inline int getNbPoints(){ Forme::mesh.getNumVertices(); };

        static void common();

    protected:
    private:

        static ofMatrix4x4 model;

        static ofShader shader;
        static ofVboMesh mesh;

        float x, y, z, w, h, d, s;
        float rotationY;
        float cpt;


};

#endif // FORME_H
