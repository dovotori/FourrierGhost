#include "Effet.h"

Effet::Effet()
{
    //ctor
}

Effet::~Effet()
{
    //dtor
}


void Effet::setup()
{
    this->shader.load("shader/glow");

    this->renderBuffer.allocate(ofGetWidth(), ofGetHeight());

    this->renderBuffer.begin();
    ofClear(255,255,255, 0);
    this->renderBuffer.end();
}


void Effet::begin()
{
     this->renderBuffer.begin();
}


void Effet::end()
{
     this->renderBuffer.end();
}

void Effet::draw()
{
    this->shader.begin();
    this->shader.setUniformTexture("tex0", this->renderBuffer.getTextureReference(), 0);
    this->shader.setUniform2f("mouse", 1, 1);
    this->shader.setUniform2f("resolution", 100, 100);
    //this->shader.setUniform1f("fade", 0.9);

    glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(ofGetWidth(), 0); glVertex3f(ofGetWidth(), 0, 0);
	glTexCoord2f(ofGetWidth(), ofGetHeight()); glVertex3f(ofGetWidth(), ofGetHeight(), 0);
	glTexCoord2f(0, ofGetHeight());  glVertex3f(0, ofGetHeight(), 0);
	glEnd();
    this->shader.end();
}

