#pragma once

#include "ofMain.h"
#include "GrilleAttractor.h"
#include "Effet.h"
#include "Forme.h"
#include "Liaison.h"
#include "Echange.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void gotMessage(ofMessage msg);
	
	private:
		ofCamera camera1;
		ofTrueTypeFont font;
	
		GrilleAttractor grille;
		Forme forme;
		Liaison liaison;
	
		Effet effet;
	
		Echange echange;

};
