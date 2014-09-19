#ifndef IMAGEMESH_H
#define IMAGEMESH_H

#include "ofMain.h"

class ImageMesh
{
    public:
        ImageMesh();
        virtual ~ImageMesh();
        void setup();
        void update();
        void draw();
    protected:
    private:
        ofImage image;
        ofVboMesh mesh;
        float cpt;
        vector<ofVec3f> offsets;
};

#endif // IMAGEMESH_H
