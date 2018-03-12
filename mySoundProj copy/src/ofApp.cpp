#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    mySound.load("16.mp3");
    mySound.setMultiPlay(true);
    wow2.load("1.mp3");
    wow3.load("2.mp3");
    wow4.load("4.mp3");
   
    mySound.setMultiPlay(true);
    wow2.setMultiPlay(true);
    wow3.setMultiPlay(true);
    wow4.setMultiPlay(true);
    
    
    owen.load("owen.jpg");
    wowtron.load("wowtron.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    
    wowtron.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::white);
    
    wowtron.draw(0,ofGetHeight()/4);
    

//        owen.draw(ofRandom(ofGetWidth()),200);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    mySound.setSpeed(ofRandom(0.8, 1.2));
    wow2.setSpeed(ofRandom(0.8, 1.2));
    wow3.setSpeed(ofRandom(0.8, 1.2));
    wow4.setSpeed(ofRandom(0.8, 1.2));
    
    switch (key) {
        case 'a':
             mySound.play();
            break;
        case 's':
             wow2.play();
            break;
        case 'd':
             wow3.play();
            break;
        case 'f':
             wow4.play();
        case 'g':
            mySound.play();
            break;
        case 'h':
            wow2.play();
            break;
        case'j':
            wow3.play();
            break;
        case'k':
            wow4.play();
            break;

        default:
            break;
    }
    
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
    
    mySound.setSpeed(ofRandom(0.8, 1.2));
    mySound.play();



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
