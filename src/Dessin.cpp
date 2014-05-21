#include "Dessin.h"

Dessin::Dessin()
{
    //ctor
}

Dessin::~Dessin()
{
    //dtor
}


void Dessin::setup()
{
    /*Forme::common();
    for(int i = 0; i < NB_FORMES; i++)
    {
        this->forme[i].setup();
        this->forme[i].setPosition(ofRandom(-4.0, 4.0), ofRandom(-4.0, 4.0), ofRandom(-4.0, 4.0));
        this->forme[i].setSize(ofRandom(2.0, 6.0), ofRandom(0.01, 0.1), ofRandom(0.01, 0.1));
        this->forme[i].setSpeed(ofRandom(-0.2, 0.2));
    }*/
    this->imgMesh.setup();
}


void Dessin::update()
{
    /*for(int i = 0; i < NB_FORMES; i++)
    {
        this->forme[i].update();
    }*/
    //this->imgMesh.update();
}


void Dessin::draw()
{
    /*for(int i = 0; i < NB_FORMES; i++)
    {
        this->forme[i].draw();
    }*/
    this->imgMesh.draw();
}


