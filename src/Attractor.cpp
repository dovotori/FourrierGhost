#include "Attractor.h"

Attractor::Attractor()
{
    this->position.set(0.0, 0.0, 0.0);
    this->radius = 50.0;
    this->strength = -10000.0;
    this->ramp = 1.0;
}


Attractor::~Attractor()
{

}


void Attractor::setup(float x, float y, float z)
{
    this->position.set(x, y, z);
}



void Attractor::attract(Node *node)
{

    float dx = this->position.x - node->getX();
    float dy = this->position.y - node->getY();
    float dz = this->position.z - node->getZ();
    float distance = sqrt((dx * dx) + (dy * dy) + (dz * dz));

    if(distance > 0 && distance < this->radius)
    {
        float s = distance / this->radius;
        float force = 1 / pow(s, (float)(0.5 * this->ramp)) - 1;
        force = this->strength * force / this->radius;

        ofVec3f ajout, current, resultat;
        current = node->getVelocity();
        ajout.set(dx * force, dy * force, dz * force);
        resultat = current + ajout;
        node->setVelocity(resultat.x, resultat.y, resultat.z);

    }
}




