#ifndef NODE_H
#define NODE_H

#include <math.h>
#include "Vecteur3d.h"

using namespace std;


class Node
{
    public:
        float x, y, z;
        Vecteur3D velocity;
        Node();
        void setup(float x = 0, float y = 0, float z = 0);
        virtual ~Node();

        void update(bool lockX = false, bool lockY = false, bool lockZ = false);

        static void setBox(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);

    protected:
    private:
        static float minX, minY, minZ, maxX, maxY, maxZ;
        Vecteur3D pVelocity;
        float damping;  // ralentissement

};

#endif // NODE_H
