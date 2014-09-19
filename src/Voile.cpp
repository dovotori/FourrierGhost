#include "Voile.h"

Voile::Voile()
{
}


Voile::~Voile()
{
}


void Voile::setup()
{
    this->shader.load("shader/voile");
    this->screen.setMode(OF_PRIMITIVE_TRIANGLES);
    this->screen.enableIndices();

    ofVec3f point(-1.0, -1.0, 0.0);
    ofVec3f point2(-1.0, 1.0, 0.0);
    ofVec3f point3(1.0, 1.0, 0.0);
    ofVec3f point4(1.0, -1.0, 0.0);
    this->screen.addVertex(point);
    this->screen.addVertex(point2);
    this->screen.addVertex(point3);
    this->screen.addVertex(point4);
    this->screen.addIndex(0); this->screen.addIndex(1); this->screen.addIndex(2);
    this->screen.addIndex(0); this->screen.addIndex(3); this->screen.addIndex(2);
}


void Voile::update()
{
}


void Voile::draw()
{
    this->shader.begin();
    this->screen.draw();
    this->shader.end();
}


