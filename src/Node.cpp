#include "Node.h"

Node::Node()
{
    this->position.set(0.0, 0.0, 0.0);
    this->velocity.set(0.0, 0.0, 0.0);
    this->damping = 0.99;
}


float Node::minX = -1000;
float Node::minY = -1000;
float Node::minZ = -1000;
float Node::maxX = 1000;
float Node::maxY = 1000;
float Node::maxZ = 1000;


void Node::setup(float x, float y, float z)
{
    this->position.set(x, y, z);
}




Node::~Node()
{
    //dtor
}




void Node::update(bool lockX, bool lockY, bool lockZ)
{


    if(!lockX){ this->position.x += this->velocity.x; }
    if(!lockY){ this->position.y += this->velocity.y; }
    if(!lockZ){ this->position.z += this->velocity.z; }


    if(this->position.x < Node::minX)
    {
        this->position.x = Node::minX - (this->position.x - Node::minX);
        this->velocity.x *= -1;
    }

    if(this->position.x > Node::maxX)
    {
        this->position.x = Node::maxX - (this->position.x - Node::maxX);
        this->velocity.x *= -1;
    }

    if(this->position.y < Node::minY)
    {
        this->position.y = Node::minY - (this->position.y - Node::minY);
        this->velocity.y *= -1;
    }

    if(this->position.y > Node::maxY)
    {
        this->position.y = Node::maxY - (this->position.y - Node::maxY);
        this->velocity.y *= -1;
    }

    if(this->position.z < Node::minZ)
    {
        this->position.z = Node::minZ - (this->position.z - Node::minZ);
        this->velocity.z *= -1;
    }

    if(this->position.z > Node::maxZ)
    {
        this->position.z = Node::maxZ - (this->position.z - Node::maxZ);
        this->velocity.z *= -1;
    }

    this->velocity *= this->damping;

}



void Node::setBox(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
{
        Node::minX = minX;
        Node::minY = minY;
        Node::minZ = minZ;
        Node::maxX = maxX;
        Node::maxY = maxY;
        Node::maxZ = maxZ;
}



