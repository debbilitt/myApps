#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myVideoGrabber.setup(320,240);
    myColorImage.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
    myGrayscaleImage.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    myVideoGrabber.update();
    myColorImage.setFromPixels(myVideoGrabber.getPixels());
    
    myGrayscaleImage = myColorImage; //operator overloading
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myGrayscaleImage.draw(0,0);
    myColorImage.draw(myGrayscaleImage.getWidth(),0);
    myVideoGrabber.draw(0,myColorImage.getHeight());
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
