#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetVerticalSync(true);

	//OF knows to load both your vert and frag shaders together
	mShader.load("sphere/shader");
    debShader.load("repulsionShader/shader");

	//ofLoadImage(mTex, "img.jpg");

	ofLoadImage(mTex, "mercator.png");

	ofBackground(0);
	//could do a distance map thing to avoid a 2nd shader?
	bShader.load("background/shader");

	ofEnableDepthTest();

	ofEnableLighting();

	mSphere.set(100.0f, 4);


	mTex.setTextureWrap(GL_NEAREST, GL_NEAREST);
	mTex.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
	mSphere.mapTexCoordsFromTexture(mTex);

	ofDisableArbTex();

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255);

	// translate plane into center screen.
	float tx = ofGetWidth() / 2;
	float ty = ofGetHeight() / 2;
    
    
    
    ofPushMatrix();
    ofTranslate(tx, ty, 250.0);
    
    //mSphere.setMode(OF_PRIMITIVE_TRIANGLES);
    //mCamera.begin();
    
    /*globe shader*/
    
    mShader.begin();
    mShader.setUniform1f("u_time", ofGetElapsedTimef());
    mShader.setUniform2f("u_mouse", ofGetMouseX(), ofGetMouseY());
    mShader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    mShader.setUniform3f("lightPos", lightPos);
    
    float rotation = 360 - fmod(ofGetFrameNum(), 360.0);
    //ofLogNotice("rotation", ofToString(rotation));
    ofRotateY(rotation);
    
    //mSphere.draw(OF_MESH_WIREFRAME);
    mSphere.draw();
    mTex.bind();
    mShader.end();
    
    //mCamera.end();
    
    ofPopMatrix();
    
    

/*smoke background*/
    
    if(smokeShaderOn){
	bShader.begin();

	// make light direction slowly rotate
	//bShader.setUniform3f("lightDir", sin(ofGetElapsedTimef() / 10), cos(ofGetElapsedTimef() / 10), 0);
	//bShader.setUniform1f("diffuse_value", 0.5);

	bShader.setUniform1f("u_time", ofGetElapsedTimef());
	bShader.setUniform2f("u_mouse", ofGetMouseX(), ofGetMouseY());
	bShader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	bShader.end();
        
    }


    
/*repulusion shader*/

    if(spaceShaderOn){
        
    
        debShader.begin();
    
        // assign the value for range of repulsion
        debShader.setUniform1f("mouseRange", 10);
    
        float mx = (cos(ofGetElapsedTimef()*10.0))+ofGetWidth()/2;
        float my = (cos(ofGetElapsedTimef()*3.0))+ofGetHeight()/2;
    
        //pointPos connected to mx my
        debShader.setUniform2f("mousePos", mx, my);
    
        float percentX = mouseX / (float)ofGetWidth();
        percentX = ofClamp(percentX, 0, 1);
    
    
        //creating colors mapped to mouse
        ofFloatColor colorOne = ofColor(25,255,251);
        ofFloatColor colorTwo = ofColor(155,25,255);
        ofFloatColor colorNew = colorOne.getLerped(colorTwo, percentX);
    
        float mouseColor[4] = {colorNew.r, colorNew.g, colorNew.b, colorNew.a};
    
        debShader.setUniform4fv("mouseColor", &mouseColor[0]);
    
        
    for(int i = 0; i<100; i++){
        for( int k = 0; k <100; k++){
            ofDrawEllipse(i*20, k*20, 2, 2);
        }
    }
    
    debShader.end();
        
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'r') {
		mShader.load("sphere/shader");
		bShader.load("background/shader");
        
    } else {
    
    }
    
    if (key == '1') {
        spaceShaderOn = true;
        smokeShaderOn = false;
    }
    else if (key == '2') {
        spaceShaderOn = false;
        smokeShaderOn = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
