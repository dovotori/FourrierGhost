#include "Transition.h"

Transition::Transition()
{
    //ctor
    this->cpt = 0;
	this->isFinish = true;
	this->duration = 0;

	this->origine = 0;
	this->destination = 1;
}

Transition::~Transition()
{
    //dtor
}

void Transition::setup(float origine, float destination, unsigned int duration){

    this->isFinish = false;
    this->cpt = 0;

    this->origine = origine;
    this->destination = destination;
    this->duration = duration;

}


float Transition::update(){

    if(!this->isFinish)
    {
        if(this->cpt >= this->duration) {
            this->isFinish = true;
            return this->destination;
        } else {
            this->cpt++;
            float currentPosition = this->origine;
            currentPosition = this->linearTween(this->cpt, this->origine, this->destination-this->origine, this->duration);
            return currentPosition;
        }
    } else {
        return this->destination;
    }

}

float Transition::linearTween(float t, float b, float c, unsigned int d) {
	return c*t/d+b;
}



