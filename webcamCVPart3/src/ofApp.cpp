#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myVideoGrabber.setup(320,240);
    
    myColorImage.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
   
    myGrayscaleImage.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
    
    myBackground.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
    
    grayDifference.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    myVideoGrabber.update();
  
    
    if(myVideoGrabber.isFrameNew()){
        
        myColorImage.setFromPixels(myVideoGrabber.getPixels());
        
        myGrayscaleImage = myColorImage; //operator overloading
        
        if (ofGetElapsedTimeMillis()< 1.0f) {
            myBackground = myGrayscaleImage;
            
        }
        
        grayDifference.absDiff(myGrayscaleImage, myBackground); //mom and dad, two parties, takes the difference
        grayDifference.threshold(40); // determines the threshold of the gray difference lower is closer to white, higher is closer to black, 255 is the highest
        
    }
    

    
    myContourFinder.findContours(grayDifference, 10, 100, 30, false);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myGrayscaleImage.draw(0,0);
    
    myColorImage.draw(myGrayscaleImage.getWidth(),0);
    
    myVideoGrabber.draw(0,myColorImage.getHeight());
    
    grayDifference.draw(myGrayscaleImage.getWidth(),myColorImage.getHeight());
    
    grayDifference.getTexture(); //use texture of gray difference somehow
    
    
    //.size is like the length of a vector
//    
//    for (int i=0; i< myContourFinder.blobs.size(); i++){
//        ofSetColor(255,255,255);
//        ofFill();
//        ofDrawEllipse(myContourFinder.blobs[i].centroid, 50,50);
//    }

    
    for(auto &blob : myContourFinder.blobs){
        ofSetColor(255,255,255);
        ofFill();
        ofDrawEllipse(blob.centroid, 10,10);
    }
    
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
