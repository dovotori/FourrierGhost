#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){


	// PARAMETRES OPENGL
    ofEnableDepthTest();
    ofSetFrameRate(50);
    ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	
	
    // CAMERA
	this->camera1.setPosition(0, 0, 200);
	this->camera1.lookAt(ofVec3f(0, 0, 0));
	this->camera1.setNearClip(0.01f);
	this->camera1.setFarClip(400.0f);
	this->camera1.setFov(50.0);
	
    //this->font.loadFont("font/sourcePro.otf",14, true, true);
	
    this->grille.setup();
	
    Forme::common();	
    this->forme.setup();
	
    int nb = this->forme.getMesh().getNumVertices();
    if(nb > this->grille.getMesh().getNumVertices()){ nb = this->grille.getMesh().getNumVertices(); }
    this->liaison.setup(nb);
	
    //this->effet.setup();
	
    this->echange.setup();



}

//--------------------------------------------------------------
void testApp::update(){

	this->echange.update();
    this->forme.update();
    this->liaison.update(this->forme.getMesh(), this->grille.getMesh(), this->forme.getModelMatrix());
    //this->grille.setClick(this->echange.getClick());
    //this->grille.interaction(this->echange.getVar()[0], this->echange.getVar()[1]);

}

//--------------------------------------------------------------
void testApp::draw(){

	//this->effet.begin();
	ofSetColor(255);
	
    this->camera1.begin();
    ofBackground(100);
	
    ofPushMatrix();
    //ofRotateX(ofGetElapsedTimeMillis()*0.01);
    //ofRotateY(ofGetElapsedTimeMillis()*0.01);
	
    this->grille.draw(this->camera1, mouseX, mouseY);
    this->forme.draw();
    this->liaison.draw();
	
	
    ofPopMatrix();
	
    this->camera1.end();
    //this->effet.end();
	
    //this->effet.draw();
	
	
	
    stringstream ss;
    ss << ofGetFrameRate() << " fps";
	ofSetColor(0);
    //this->font.drawString(ss.str(), 100, ofGetHeight()/8);
    //ofDrawBitmapString("Fourrier Ghost", ofPoint( 100, ofGetWindowHeight()-100 ) );
    ofDrawBitmapString(ss.str(), ofPoint( 10, ofGetWindowHeight()-10 ) );

}


//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	this->grille.setClick(true);
    ofVec3f worldPos(x, y, 1);
    worldPos = this->camera1.screenToWorld(worldPos);
	
    this->grille.interaction(worldPos.x, worldPos.y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	this->grille.reset();
}

void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}
