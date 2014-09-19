#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // PARAMETRES OPENGL
    ofEnableDepthTest();
    ofSetFrameRate(50);
    ofSetVerticalSync(false);
	ofEnableAlphaBlending();

    this->camera.setup();

    this->dessin.setup();


}

//--------------------------------------------------------------
void ofApp::update(){

    this->camera.updateAngle(ofGetElapsedTimeMillis() * 0.0001);
    this->dessin.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    stringstream ss;
    ss << ofGetFrameRate() << " fps";
    ofDrawBitmapString(ss.str(), ofPoint( 10, ofGetWindowHeight()-10 ) );

    ofBackgroundGradient(ofColor(180), ofColor(100));

    this->dessin.draw(this->camera);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    this->rayPicking.update(x, y, this->camera);
    ofVec3f collision = this->rayPicking.getPositionSurRayon(this->camera);

    this->dessin.mouseDragged(collision.x, collision.y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    this->dessin.mousePressed();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
     this->dessin.mouseReleased();
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}



