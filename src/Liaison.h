#ifndef LIAISON_H
#define LIAISON_H

#include "ofMain.h"
#include "Camera.h"
#include <vector>


class Liaison
{
    public:
        Liaison();
        virtual ~Liaison();
        void setup(unsigned int nb = 10);
        void draw(Camera *camera);

		inline ofVbo* getMesh(){ return &this->mesh; }
        inline void setColor(float r, float v, float b, float a) { this->shader.begin(); this->shader.setUniform4f("color", r/255.0, v/255.0, b/255.0, a); this->shader.end(); }
		inline int getNb(){ return this->nb; }

    protected:
    private:
        ofVbo mesh;
        ofMatrix4x4 model;
        ofShader shader;
        unsigned int nb;
};

#endif // LIAISON_H
