#include "RayPicking.h"

RayPicking::RayPicking()
{
    //ctor
}

RayPicking::~RayPicking()
{
    //dtor
}



void RayPicking::update(int x, int y, Camera camera)
{

    // normalize -1, 1
    float newX = (2.0f * x) / ofGetWindowWidth() - 1.0f;
    float newY = 1.0f - (2.0f * y) / ofGetWindowHeight(); // reverse Y

    ofVec4f rayViewport(newX, newY, -1.0, 1.0);
    ofVec4f rayEye = rayViewport * camera.getProjectionMatrix().getInverse();
    rayEye = ofVec4f(rayEye.x, rayEye.y, -1.0, 0.0); // dit de ne pas etre un point mais de se projeter en avant
    ofVec4f rayWorld = rayEye * camera.getViewMatrix().getInverse();
    rayWorld.normalize();

    this->rayon = rayWorld;

}

ofVec3f RayPicking::getPositionSurRayon(Camera camera)
{
    ofVec3f origine = camera.getPosition();
    float distance = origine.z;
    return origine + (this->rayon * distance);
}







