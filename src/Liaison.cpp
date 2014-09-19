#include "Liaison.h"

Liaison::Liaison()
{
    //ctor
}

Liaison::~Liaison()
{
    //dtor
}



void Liaison::setup(unsigned int nb)
{
    this->nb = nb;
    this->shader.load("shader/basic");
    this->model.makeIdentityMatrix();

	vector<ofVec3f> vert(this->nb*2);
    for(int i = 0; i < this->nb*2; i++){ vert[i].set(0,0,0); }
	this->mesh.setVertexData( &vert[0], this->nb*2, GL_STREAM_DRAW );
}




void Liaison::draw(Camera *camera)
{
    this->shader.begin();
    this->shader.setUniformMatrix4f("model", this->model);
    this->shader.setUniformMatrix4f("view", camera->getViewMatrix());
    this->shader.setUniformMatrix4f("projection", camera->getProjectionMatrix());
    this->mesh.draw(GL_LINES, 0, this->nb*2);
    this->shader.end();
}


