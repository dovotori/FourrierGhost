#include "Forme.h"

Forme::Forme()
{
    //ctor
    this->x = this->y = this->z = 0.0;
    this->w = this->h = this->d = 20.0;
    this->s = 0.4;
    this->rotationY = 0.0;

}

Forme::~Forme()
{
    //dtor
}


ofShader Forme::shader;
ofVboMesh Forme::mesh;
ofMatrix4x4 Forme::model;



void Forme::common()
{
    // SHADER
    Forme::shader.load("shader/custom");

     // OBJET
    Forme::mesh.setMode(OF_PRIMITIVE_POINTS);

    LoadOBJ obj;
    obj.setup(ofFilePath::getAbsolutePath(".")+"/objet/sphere.obj");

    float *vertice = obj.getAbsoluteCoor(PGL_VERTICES);
    float *normale = obj.getAbsoluteCoor(PGL_NORMALES);


    for(unsigned int i = 0; i < obj.getNb(PGL_FACES) * 3 * 3; i += 3)
    {
        ofVec3f point(vertice[i], vertice[i+1], vertice[i+2]);
        ofVec3f point2(normale[i], normale[i+1], normale[i+2]);
        Forme::mesh.addVertex(point);
        Forme::mesh.addNormal(point2);
    }

    // MATRIX
	Forme::model.makeIdentityMatrix();

}


void Forme::setup()
{
    this->cpt = 0.0;
}


void Forme::update()
{
    this->rotationY += this->s;
    this->cpt += 0.01;
    this->w = 10.0 + ((1 + cos(this->cpt)) * 100.0);
    this->h = this->w;
    this->d = this->w;
}







void Forme::draw(Camera *camera)
{

    Forme::model.makeIdentityMatrix();
    Forme::model.translate(this->x, this->y, this->z);
    Forme::model.rotate(this->rotationY, 0.0f, 1.0f, 0.0f);
    Forme::model.scale(this->w, this->h, this->d);

    Forme::shader.begin();
    Forme::shader.setUniformMatrix4f("model", Forme::model);
    Forme::shader.setUniformMatrix4f("view", camera->getViewMatrix());
    Forme::shader.setUniformMatrix4f("projection", camera->getProjectionMatrix());
    Forme::mesh.draw();
    Forme::shader.end();

}


void Forme::interaction()
{

}





