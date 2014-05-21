#ifndef GRILLEATTRACTOR_H
#define GRILLEATTRACTOR_H

#include "ofMain.h"
#include "Node.h"
#include "Attractor.h"
#include <vector>


#define NB_NODES 200


class GrilleAttractor
{
    public:
        GrilleAttractor();
        virtual ~GrilleAttractor();
        void setup();
        void update();
        void draw(ofCamera cam, int mouseX, int mouseY);
        void interaction(int x, int y);
        void reset();

        inline void setClick(bool etat){ this->click = etat; };
        inline void setPosition(int x, int y){ this->attractor.setPosition(x, y); };
        inline void setStrength(float value){ this->attractor.setStrength(value); };
        inline void setRadius(float value){ this->attractor.setRadius(value); };

        inline ofVec2f getNearest(){ return this->nearestVertex; };
        inline ofVboMesh getMesh(){ return this->mesh; };

    protected:
    private:
        vector<Node> node;
        Attractor attractor;
        ofShader shader;
        ofVboMesh mesh;
        bool click;
        ofVec2f nearestVertex;

};

#endif // GRILLEATTRACTOR_H
