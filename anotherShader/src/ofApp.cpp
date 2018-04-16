#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
//    ofSetVerticalSync(false);
//    ofEnableAlphaBlending();
    
    if(ofIsGLProgrammableRenderer()){
      mShader.load("repulsionShader/shader");
      newShader.load("newShader/shader");
    
    }
    

//   float planeScale = 0.50;
//    int planeWidth = ofGetWidth();
//    int planeHeight = ofGetHeight();
//    int planeGridSize = 2.0;
//    int planeColumns = planeWidth / planeGridSize;
//    int planeRows = planeHeight / planeGridSize;
//    
//    plane.set(planeWidth, planeHeight, planeColumns, planeRows, OF_PRIMITIVE_TRIANGLES);

//    ofEnableDepthTest();
//
//    mPattern.load("pattern.jpeg");
//    
//    plane.set(mPattern.getWidth()/2,mPattern.getHeight()/2,50,2);
//    plane.mapTexCoordsFromTexture(mPattern.getTexture());
    

    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    

    /*image */
  
//    mPattern.getTexture().bind();
//    
//    mShader.begin();
//    
//    mShader.setUniform1f("u_time", ofGetElapsedTimef());
//    
//    // the mouse/touch Y position changes the rotation of the plane.
//    float percentY = mouseY / (float)ofGetHeight();
//    float rotation = ofMap(percentY, 0, 1, -60, 60, true) + 60;
//    ofRotate(rotation, 1, 0, 0);
//    
//    plane.draw();
//    
//    mShader.end();
//    
//    mPattern.getTexture().unbind();

    
/*new shader*/
//    newShader.begin();
//    
//        //we also pass in the mouse position
//        //we have to transform the coords to what the shader is expecting which is 0,0 in the center and y axis flipped.
//    newShader.setUniform2f("mouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY );
//    
//    ofPushMatrix();
//    ofColor colorLeft = ofColor(155,25,255);
//    ofColor colorRight = ofColor(25,255,251);
//    ofColor colorMix = colorLeft.getLerped(colorRight, percentX);
//    ofSetColor(colorMix);
//    
//    ofFill();
//
//        for (int i = 0; i< 100; i++){
//            for (int j= 0; j< 100; j++) {
//            
//                ofDrawRectangle(i, j, 2, 2);
//            
//            }
//        }
//    
//    ofPopMatrix();
//    
//     ofPushMatrix();
//    ofColor colorOne = ofColor(25,255,251);
//    ofColor colorTwo = ofColor(155,25,255);
//    ofColor colorNew = colorOne.getLerped(colorTwo, percentX);
//    ofSetColor(colorNew);
//
//    ofFill();
//
//
//    ofTranslate(ofGetWidth()/2, 0);
//
//    for (int i = 0; i< ofGetWidth()/2; i++){
//        for (int j= 0; j< ofGetHeight(); j++) {
//
//            ofDrawRectangle(i, j, 2, 2);
//
//        }
//    }
//
//
//    ofPopMatrix();
//    
//    
//    newShader.end();
    
/*repulusion shader*/
    
    mShader.begin();
    

    
    float mx = (cos(ofGetElapsedTimef()*10.0))+ofGetWidth()/2;
    float my = (cos(ofGetElapsedTimef()*3.0))+ofGetHeight()/2;
    
    
    // we can pass in a single value into the shader by using the setUniform1 function.
    // if you want to pass in a float value, use setUniform1f.
    // if you want to pass in a integer value, use setUniform1i.
    mShader.setUniform1f("mouseRange", 20);
    
    // we can pass in two values into the shader at the same time by using the setUniform2 function.
    // inside the shader these two values are set inside a vec2 object.
    mShader.setUniform2f("mousePos", mx, my);
    
    float percentX = mouseX / (float)ofGetWidth();
    percentX = ofClamp(percentX, 0, 1);


    ofFloatColor colorOne = ofColor(25,255,251);
    ofFloatColor colorTwo = ofColor(155,25,255);
    ofFloatColor colorNew = colorOne.getLerped(colorTwo, percentX);

    
    // create a float array with the color values.
   float mouseColor[4] = {colorNew.r, colorNew.g, colorNew.b, colorNew.a};
    
    // we can pass in four values into the shader at the same time as a float array.
    // we do this by passing a pointer reference to the first element in the array.
    // inside the shader these four values are set inside a vec4 object.
    mShader.setUniform4fv("mouseColor", &mouseColor[0]);
    

    for(int i = 0; i<100; i++){
            for( int k = 0; k <100; k++){
                ofDrawEllipse(i*20, k*20, 2, 2);
            }
        }
    
    mShader.end();

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
