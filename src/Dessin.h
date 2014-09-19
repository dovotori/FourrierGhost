#ifndef DESSIN_H
#define DESSIN_H


#include "ofMain.h"
#include "GrilleAttractor.h"
#include "Forme.h"
#include "Liaison.h"
#include "Echange.h"
#include "Voile.h"
#include "Camera.h"


class Dessin
{
    public:
        Dessin();
        virtual ~Dessin();
        void setup();
        void update();
        void draw(Camera camera);

        void mouseDragged(int x, int y);
        void mousePressed();
        void mouseReleased();

    protected:
    private:
        GrilleAttractor grille;
        Forme forme;
        Liaison liaison;
        Voile voile;


        Echange echange;

};

#endif // DESSIN_H
