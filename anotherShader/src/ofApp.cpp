#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    if(ofIsGLProgrammableRenderer()){
      mShader.load("shader2/shader");
    
    }
    

//   float planeScale = 0.50;
//    int planeWidth = ofGetWidth();
//    int planeHeight = ofGetHeight();
//    int planeGridSize = 2.0;
//    int planeColumns = planeWidth / planeGridSize;
//    int planeRows = planeHeight / planeGridSize;
//    
//    plane.set(planeWidth, planeHeight, planeColumns, planeRows, OF_PRIMITIVE_TRIANGLES);

    ofEnableDepthTest();

    mPattern.load("pattern.jpeg");
    
    plane.set(mPattern.getWidth()/2,mPattern.getHeight()/2,50,2);
    plane.mapTexCoordsFromTexture(mPattern.getTexture());
    

    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    // translate plane into center screen.
    float tx = ofGetWidth()/2;
    float ty = ofGetHeight()/2;
    ofTranslate(tx, ty);

    
    float percentX = mouseX / (float)ofGetWidth();
    percentX = ofClamp(percentX, 0, 1);
    
    // the mouse/touch X position changes the color of the plane.
    // please have a look inside the frag shader,
    // we are using the globalColor value that OF passes into the shader everytime you call ofSetColor().
    ofColor colorLeft = ofColor::aquamarine;
    ofColor colorRight = ofColor::lavenderBlush;
    ofColor colorMix = colorLeft.getLerped(colorRight, percentX);
    ofSetColor(colorMix);
    
    
    /*image */
  
    mPattern.getTexture().bind();
    
    mShader.begin();
    
    mShader.setUniform1f("u_time", ofGetElapsedTimef());
    
    // the mouse/touch Y position changes the rotation of the plane.
    float percentY = mouseY / (float)ofGetHeight();
    float rotation = ofMap(percentY, 0, 1, -60, 60, true) + 60;
    ofRotate(rotation, 1, 0, 0);
  
    
    plane.draw();
    
    mShader.end();
    
    mPattern.getTexture().unbind();



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
