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

    LoadOBJ obj;
    obj.setup("data/objet/plan.obj");
    float *vertice = obj.getCoor(PGL_VERTICES);

    for(unsigned int i = 0; i < obj.getNb(PGL_VERTICES) * 3; i += 3)
    {
        ofVec3f point(vertice[i], vertice[i+1], vertice[i+2]);
        this->screen.addVertex(point);
    }
    unsigned int *id = obj.getId(PGL_VERTICES);
    for(unsigned int i = 0; i < obj.getNb(PGL_FACES) * 3; i++)
    {
        this->screen.addIndex(id[i]);
    }

    this->cpt = 0.0;
    this->opacity = 1.0;
    this->timer.setup(50, false);

}


void Voile::update()
{
    if(timer.isTimerFinished())
    {
        this->cpt += 0.01;
        this->shader.begin();
        this->shader.setUniform1f("cpt", this->cpt);
        this->shader.setUniform1f("opacity", this->opacity);
        this->shader.end();

        this->timer.reset();
        this->timer.setTimer(100);
        this->timer.startTimer();
    }
}

void Voile::draw()
{
    ofPushMatrix();
    ofRotateX(90);
    ofTranslate(0, 5, 0);
    ofScale(3, 1, 2);

    this->shader.begin();
    this->screen.draw();
    this->shader.end();

    ofPopMatrix();
}


