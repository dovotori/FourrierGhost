#include "Camera.h"

Camera::Camera()
{
    //ctor
}

Camera::~Camera()
{
    //dtor
}


void Camera::setup(){

    this->position.set(0, 0, 400);
    this->target.set(0, 0, 0);
    this->angle = 40.0;
    this->near = 1.0;
    this->far = 1000.0;

    this->updateView();
    this->updateProjection();

}


void Camera::updateAngle(float angle){
    this->angle = (cos(angle) * 70.0) + 20.0;
    this->updateProjection();
}


void Camera::updateView(){
    this->view.makeLookAtViewMatrix(this->position, this->target, ofVec3f(0, 1, 0));
}

void Camera::updateProjection(){
    this->projection.makePerspectiveMatrix(this->angle, ofGetWindowWidth()/ofGetWindowHeight(), this->near, this->far);
}




