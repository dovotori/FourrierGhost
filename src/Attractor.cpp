#include "Attractor.h"

Attractor::Attractor()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->radius = 200.0;
    this->strength = -10.0;
    this->ramp = 0.99;
}


Attractor::~Attractor()
{

}


void Attractor::setup(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}



void Attractor::attract(Node *node)
{
    float dx = this->x - node->x;
    float dy = this->y - node->y;
    float dz = this->z - node->z;
    float distance = sqrt((dx * dx) + (dy * dy) + (dz * dz));

    if(distance > 0 && distance < this->radius)
    {
        float s = distance / this->radius;
		float puissance = this->ramp*0.5;
        float force = 1 / pow(s, puissance) - 1;
        force = this->strength * force/this->radius;

        node->velocity.x += dx * force;
        node->velocity.y += dy * force;
        node->velocity.z += dz * force;

    }
}




