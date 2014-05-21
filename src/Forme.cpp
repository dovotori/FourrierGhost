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
ofMatrix4x4 Forme::view;
ofMatrix4x4 Forme::projection;

void Forme::common()
{
    // SHADER
    //Forme::shader.load("shader/custom");

     // OBJET
    Forme::mesh.setMode(OF_PRIMITIVE_POINTS);

    LoadOBJ obj;
	cout << ofFilePath::getAbsolutePath(".") << endl;
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
	Forme::view.makeLookAtViewMatrix(ofVec3f(0, 0, 200), ofVec3f(0, 0, 0), ofVec3f(0, 1, 0));
	Forme::projection.makePerspectiveMatrix(50.0, ofGetWindowWidth()/ofGetWindowHeight(), 0.01f, 400.0f);

}


void Forme::setup()
{

}


void Forme::update()
{
    this->rotationY += this->s;
    //shader.begin();
    //shader.setUniform1f("cpt", this.s);
    //shader.end();
}







void Forme::draw()
{

    ofPushMatrix();
    ofTranslate(this->x, this->y, this->z);
    ofRotateY(this->rotationY);
    ofScale(this->w, this->h, this->d);

    Forme::model.makeIdentityMatrix();
    Forme::model.translate(this->x, this->y, this->z);
    Forme::model.rotate(this->rotationY, 0.0f, 1.0f, 0.0f);
    Forme::model.scale(this->w, this->h, this->d);

    Forme::shader.begin();
    Forme::shader.setUniformMatrix4f("model", Forme::model);
    Forme::shader.setUniformMatrix4f("view", Forme::view);
    Forme::shader.setUniformMatrix4f("projection", Forme::projection);
    Forme::mesh.draw();
    Forme::shader.end();

    ofPopMatrix();
 
}


void Forme::interaction(int sens)
{

}




void Forme::setPosition(float x, float y, float z)
{

    this->x = x;
    this->y = y;
    this->z = z;

}


void Forme::setSize(float w, float h, float d)
{

    this->w = w;
    this->h = h;
    this->d = d;

}



void Forme::setSpeed(float s)
{
    this->s = s;
}






