#ifndef GRILLEATTRACTOR_H
#define GRILLEATTRACTOR_H

#include "ofMain.h"
#include "Node.h"
#include "Attractor.h"
#include "Camera.h"
#include "Forme.h"
#include <vector>



class GrilleAttractor
{
    public:
        GrilleAttractor();
        virtual ~GrilleAttractor();
        void setup(int nbNode = 10, float distanceInterval = 10.0);
        void update(unsigned int nbLiaison, ofVbo *meshLiaison, ofVboMesh *formeMesh, ofMatrix4x4 formeView);
        void draw(Camera *camera);
        void reset();

        inline void setNbNodes(int valeur){ this->nbNodes = valeur; };
        inline void setDistanceInterval(float valeur){ this->distanceInterval = valeur; };
        inline void setActive(bool etat){ this->isActive = etat; };
        inline void setStrength(float value){ this->attractor.setStrength(value); };
        inline void setRadius(float value){ this->attractor.setRadius(value); };
        inline void setAttractorPosition(float x, float y, float z = 0.0){ this->attractor.setPosition(x, y, z); }
        inline void setColor(float r, float v, float b, float a) { this->shader.begin(); this->shader.setUniform4f("color", r/255.0, v/255.0, b/255.0, a); this->shader.end(); }
        inline void setPointWeight(float valeur) { this->shader.begin(); this->shader.setUniform1f("pointWeight", valeur); this->shader.end(); }

        inline void setRotation(float value = 0.0, float x = 1.0, float y = 0.0, float z = 0.0){ this->model.rotate(value, x, y, z); }

        inline int getNbNodes(){ return this->nbNodes*this->nbNodes; }
        inline ofVbo getVbo(){ return this->mesh; }

    protected:
    private:
        vector<Node> node;
        Attractor attractor;
        ofShader shader;
        ofVbo mesh;
        ofMatrix4x4 model;

        bool isActive;
        int nbNodes;
        float distanceInterval;

};

#endif // GRILLEATTRACTOR_H
