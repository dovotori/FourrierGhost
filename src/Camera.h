#ifndef CAMERA_H
#define CAMERA_H

#include "ofMain.h"

class Camera
{
    public:
        Camera();
        virtual ~Camera();
        void setup();
        void updateView();
        void updateProjection();

        inline void setPosition(float x, float y, float z){ this->position.set(x, y, z); };
        inline void setTarget(float x, float y, float z){ this->target.set(x, y, z); };
        inline void setAngle(float valeur){ this->angle = valeur; };

        void updateAngle(float angle);

        inline ofMatrix4x4 getViewMatrix(){ return this->view; }
        inline ofMatrix4x4 getProjectionMatrix(){ return this->projection; }
        inline float getAngle(){ return this->angle; };
        inline ofVec3f getPosition(){ return this->position; };
        inline float getDistanceFocale(){ return this->near; };

    protected:
    private:

        ofMatrix4x4 view, projection;
        ofVec3f position, target;
        float angle, near, far;
        float cpt;
};

#endif // CAMERA_H
