#include "Dessin.h"

Dessin::Dessin()
{

}

Dessin::~Dessin()
{

}


void Dessin::setup()
{
    Forme::common();
    this->forme.setup();
    this->grille.setup(100, 2.0);
    this->grille.setStrength(0.1);
    this->echange.setup();

	int nbLiaison = this->grille.getNbNodes();
	if(nbLiaison > this->forme.getNbPoints()){ nbLiaison = this->forme.getNbPoints(); }

    this->liaison.setup(nbLiaison);
    this->liaison.setColor(255, 100, 100, 0.2);
    this->voile.setup();
}


void Dessin::update()
{
    this->echange.update();
    this->forme.update();
	this->grille.update(this->liaison.getNb(), this->liaison.getMesh(), this->forme.getMesh(), this->forme.getModelMatrix());
    if(this->echange.getDraw(3)){ this->voile.update(); }
}


void Dessin::draw(Camera camera)
{

    this->grille.setRotation(0.1, 1.0, 1.0, 0.0);
    this->grille.draw(&camera);
    this->forme.draw(&camera);
    this->liaison.draw(&camera);

    if(this->echange.getDraw(3)){ this->voile.draw(); }
}



//--------------------------------------------------------------
void Dessin::mouseDragged(int x, int y){
    this->grille.setAttractorPosition(x, y, ofRandom(-10.0, 10.0));
}

//--------------------------------------------------------------
void Dessin::mousePressed(){
    this->grille.setActive(true);
}

//--------------------------------------------------------------
void Dessin::mouseReleased(){
	//this->grille.reset();
    this->grille.setActive(false);
}

