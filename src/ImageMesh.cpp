#include "ImageMesh.h"

ImageMesh::ImageMesh()
{
    //ctor
}

ImageMesh::~ImageMesh()
{
    //dtor
}

void ImageMesh::setup()
{
    this->image.loadImage("images/image.png");

    this->mesh.setMode(OF_PRIMITIVE_LINES);

    float intensityThreshold = 100.0;
    int step = 6;

    int w = this->image.getWidth();
    int h = this->image.getHeight();
    for (int x = 0; x < w; x += step)
    {
        for (int y = 0; y < h; y += step)
        {
            ofColor c = this->image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                ofVec3f pos(x/50.0, y/50.0, ofRandom(-4.0, 4.0));
                this->mesh.addVertex(pos);
                this->mesh.addColor(c);
                this->offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
            }
        }
    }

    float connectionDistance = 1.0;
    int numVerts = this->mesh.getNumVertices();
    for (int a = 0; a < numVerts; ++a)
    {
        ofVec3f verta = this->mesh.getVertex(a);
        for (int b = a+1; b < numVerts; ++b)
        {
            ofVec3f vertb = this->mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                this->mesh.addIndex(a);
                this->mesh.addIndex(b);
            }
        }
    }


    this->cpt = 0.0;
}



void ImageMesh::update()
{

    int numVerts = mesh.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i);

        float time = ofGetElapsedTimef();
        float timeScale = 5.0;
        float displacementScale = 0.75;
        ofVec3f timeOffsets = offsets[i];

        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
        this->mesh.setVertex(i, vert);
    }
}



void ImageMesh::draw()
{
    this->cpt += 0.6;

    ofPushMatrix();
    ofRotateX(this->cpt);
    ofRotateY(this->cpt);
    ofTranslate(-(this->image.getWidth()/50.0)*0.5, -(this->image.getHeight()/50.0)*0.5, 0.0);
    this->mesh.draw();
    ofPopMatrix();
}

