#include "GrilleAttractor.h"

GrilleAttractor::GrilleAttractor()
{

}

GrilleAttractor::~GrilleAttractor()
{
    //dtor
}


void GrilleAttractor::setup()
{
    ofEnablePointSprites();
    //Node::setBox(-ofGetWidth()/2, -ofGetHeight()/2, -10, ofGetWidth()/2, ofGetHeight()/2, 10);
    int cpt = 0;
    this->node.reserve(NB_NODES*NB_NODES);

    for(int y = -NB_NODES/2; y < NB_NODES/2; y++)
    {
        for(int x = -NB_NODES/2; x < NB_NODES/2; x++)
        {
            this->node[cpt] = Node();
            this->node[cpt].setup(x*4, y*4 , 0);
            ofVec3f point(x*4, y*4 , 0);
            this->mesh.addVertex(point);
            cpt ++;
        }
    }

    this->attractor.setup();

    this->mesh.setMode(OF_PRIMITIVE_POINTS);
    this->shader.load("shader/attractor");
    this->click = false;
}




void GrilleAttractor::draw(ofCamera cam, int mouseX, int mouseY)
{


	ofVec2f mouse(mouseX, mouseY);

    float nearestDistance = 0;

    for(int i = 0; i < NB_NODES*NB_NODES; i++)
    {
        /*
        // trait plus proche entre node et la souris
        ofVec3f cur = cam.worldToScreen(this->mesh.getVertex(i));
        float distance = cur.distance(mouse);
        if(i == 0 || distance < nearestDistance) {
			nearestDistance = distance;
			this->nearestVertex = cur;
		}
		*/

        if(this->click)
        {
            this->attractor.attract(&this->node[i]);
        }
        this->node[i].update();

        ofVec3f vert = this->mesh.getVertex(i);
        vert.x = this->node[i].x;
        vert.y = this->node[i].y;
        vert.z = this->node[i].z;
        this->mesh.setVertex(i, vert);

    }

    ofPushMatrix();
    this->shader.begin();
    this->mesh.draw();
    this->shader.end();
    ofPopMatrix();



}



void GrilleAttractor::reset(){

    int cpt = 0;
    for(int y = -NB_NODES/2; y < NB_NODES/2; y++)
    {
        for(int x = -NB_NODES/2; x < NB_NODES/2; x++)
        {
            this->node[cpt] = Node();
            this->node[cpt].setup(x*4, y*4 , 0);
            ofVec3f point(x*4, y*4 , 0);
            this->mesh.setVertex(cpt, point);
            cpt ++;
        }
    }

}


void GrilleAttractor::interaction(int x, int y)
{
    this->attractor.setPosition(x, y);
}





