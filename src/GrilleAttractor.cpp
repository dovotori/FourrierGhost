#include "GrilleAttractor.h"

GrilleAttractor::GrilleAttractor()
{

}

GrilleAttractor::~GrilleAttractor()
{
    //dtor
}


void GrilleAttractor::setup(int nbNode, float distanceInterval)
{
    ofEnablePointSprites();
    this->nbNodes = nbNode;
    this->distanceInterval = distanceInterval;
    this->node.reserve(nbNodes*nbNodes);
	vector<ofVec3f> vert(nbNodes*nbNodes);
    for(int i = 0; i < nbNodes*nbNodes; i++){ vert[i].set(0.0, 0.0, 0.0); }
	this->mesh.setVertexData( &vert[0], nbNodes*nbNodes, GL_STREAM_DRAW );

    this->reset();
    this->attractor.setup();
    this->shader.load("shader/attractor");

    this->setColor(255.0, 255.0, 255.0, 1.0);
    this->setPointWeight(1.0);
    this->isActive = false;
    this->model.makeIdentityMatrix();

}




void GrilleAttractor::update(unsigned int nbLiaison, ofVbo *meshLiaison, ofVboMesh *formeMesh, ofMatrix4x4 formeView)
{
    // APPLIQUE LES COOR POUR LA GRILLE
	vector<ofVec3f> vert(this->nbNodes*this->nbNodes);
    for(int i = 0; i < this->nbNodes*this->nbNodes; i++)
    {
        if(this->isActive)
        {
            this->attractor.attract(&this->node[i]);
        }
        this->node[i].update();
        vert[i].set(this->node[i].getX(), this->node[i].getY(), this->node[i].getZ());
    }
    this->mesh.updateVertexData(&vert[0], this->nbNodes*this->nbNodes);


    // APPLIQUE LES COOR POUR LES LIAISONS
    unsigned int cptLiaison = 0;
    vector<ofVec3f> vertLiaison(nbLiaison*2);
    for(int i = 0; i < nbLiaison; i++, cptLiaison += 2)
    {
        int mapI = ofMap(i, 0, nbLiaison, 0, this->nbNodes*this->nbNodes);
        vertLiaison[cptLiaison].set(vert[mapI] * this->model);
        vertLiaison[cptLiaison+1].set(formeMesh->getVertex(i) * formeView);
    }
	meshLiaison->updateVertexData(&vertLiaison[0], nbLiaison*2);

}




void GrilleAttractor::draw(Camera *camera)
{

    this->shader.begin();
    this->shader.setUniformMatrix4f("model", this->model);
    this->shader.setUniformMatrix4f("view", camera->getViewMatrix());
    this->shader.setUniformMatrix4f("projection", camera->getProjectionMatrix());
    this->mesh.draw(GL_POINTS, 0, nbNodes*nbNodes);
    this->shader.end();

}



void GrilleAttractor::reset(){

	vector<ofVec3f> vert(nbNodes*nbNodes);
    int cpt = 0;

    for(int y = -nbNodes/2; y < nbNodes/2; y++)
    {
        for(int x = -nbNodes/2; x < nbNodes/2; x++)
        {
            float posX = x * distanceInterval;
            float posY = y * distanceInterval;
            this->node[cpt] = Node();
            this->node[cpt].setup(posX, posY, 0);

			vert[cpt].set(posX, posY, 0);
            cpt ++;
        }
    }
	this->mesh.updateVertexData(&vert[0], nbNodes*nbNodes);
}






