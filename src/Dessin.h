#ifndef DESSIN_H
#define DESSIN_H

#define NB_FORMES 100

#include "Forme.h"
#include "ImageMesh.h"

class Dessin
{
    public:
        Dessin();
        virtual ~Dessin();
        void setup();
        void update();
        void draw();
    protected:
    private:
         Forme forme[NB_FORMES];
         ImageMesh imgMesh;

};

#endif // DESSIN_H
