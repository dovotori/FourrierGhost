#include "Liaison.h"

Liaison::Liaison()
{
    //ctor
}

Liaison::~Liaison()
{
    //dtor
}

void Liaison::setup(int nb)
{
    this->nb = nb;
    this->mesh.setMode(OF_PRIMITIVE_LINES);

    for(int i = 0; i < this->nb*2; i++)
    {
        this->mesh.addVertex(ofVec3f(0,0,0));
    }
}

void Liaison::update(ofVboMesh mesh1, ofVboMesh mesh2, ofMatrix4x4 matrix)
{
    /*
    ofPolyline line;
	line.addVertex(ofVec2f(-20, -20));
	line.addVertex(ofVec2f(20, 20));
	line.close();
    line.draw();
*/


    int cpt = 0;
    for(int i = 0; i < this->nb; i++, cpt += 2)
    {
        //ofVec3f cur = cam.worldToScreen(mesh.getVertex(i));
        ofVec3f v1 = mesh1.getVertex(i);
        ofVec3f v2 = mesh2.getVertex(i);

        v1 = matrix * v1;

        this->mesh.setVertex(cpt, v1);
        this->mesh.setVertex(cpt+1, v2);
    }
}

void Liaison::draw()
{
    this->mesh.draw();
}


