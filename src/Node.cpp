#include "Node.h"

Node::Node()
{
    this->x = this->y = this->z = 0.0;
    this->damping = 0.5;
}


float Node::minX = -1000;
float Node::minY = -1000;
float Node::minZ = -1000;
float Node::maxX = 1000;
float Node::maxY = 1000;
float Node::maxZ = 1000;


void Node::setup(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}




Node::~Node()
{
    //dtor
}




void Node::update(bool lockX, bool lockY, bool lockZ)
{

    this->pVelocity = this->velocity;

    if(!lockX){ this->x += this->velocity.x; }
    if(!lockY){ this->y += this->velocity.y; }
    if(!lockZ){ this->z += this->velocity.z; }


    if(this->x < Node::minX)
    {
        this->x = Node::minX - (this->x - Node::minX);
        this->velocity.x = -this->velocity.x;
    }

    if(this->x > Node::maxX)
    {
        this->x = Node::maxX - (this->x - Node::maxX);
        this->velocity.x = -this->velocity.x;
    }

    if(this->y < Node::minY)
    {
        this->y = Node::minY - (this->y - Node::minY);
        this->velocity.y = -this->velocity.y;
    }

    if(this->y > Node::maxY)
    {
        this->y = Node::maxY - (this->y - Node::maxY);
        this->velocity.y = -this->velocity.y;
    }

    if(this->z < Node::minZ)
    {
        this->z = Node::minZ - (this->z - Node::minZ);
        this->velocity.z = -this->velocity.z;
    }

    if(this->z > Node::maxZ)
    {
        this->z = Node::maxZ - (this->z - Node::maxZ);
        this->velocity.z = -this->velocity.z;
    }

    this->velocity * (1 - this->damping);

}



void Node::setBox(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
{
        Node::minX = minX;
        Node::minX = minY;
        Node::minX = minZ;
        Node::maxX = maxX;
        Node::maxX = maxY;
        Node::maxX = maxZ;
}



