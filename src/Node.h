#ifndef NODE_H
#define NODE_H

#include "ofMain.h"
#include <math.h>

using namespace std;


class Node
{
    public:
        Node();
        void setup(float x = 0, float y = 0, float z = 0);
        virtual ~Node();

        void update(bool lockX = false, bool lockY = false, bool lockZ = false);

        static void setBox(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);

        inline float getX(){ return this->position.x; }
        inline float getY(){ return this->position.y; }
        inline float getZ(){ return this->position.z; }

        inline ofVec3f getVelocity(){ return this->velocity; }
        inline void setVelocity(float x = 0, float y = 0, float z = 0){ this->velocity.set(x, y, z); }

    protected:
    private:
        ofVec3f position;
        ofVec3f velocity;
        static float minX, minY, minZ, maxX, maxY, maxZ;
        float damping;  // ralentissement

};

#endif // NODE_H
