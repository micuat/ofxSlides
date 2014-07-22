#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	ofTrueTypeFont::setGlobalDpi(72);
	
	verdana60.loadFont("verdana.ttf", 60, true, true);
	verdana60.setLineHeight(64.0f);
	verdana60.setLetterSpacing(1.037);
	
	verdana30.loadFont("verdana.ttf", 30, true, true);
	verdana30.setLineHeight(34.0f);
	verdana30.setLetterSpacing(1.035);
	
	s.loadVideos(ofToDataPath("videos"));
	
	plane.set(300, 200, 15, 10);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(54, 54, 54, 255);
	ofSetColor(240);
	
	int page;
	
	s.begin();
	
	if( s++ ) {
		verdana60.drawString("ofTitle", 30, 100);
		verdana60.drawString("ofName", 30, 400);
		verdana30.drawString("press [->] to proceed\npress [f] to go fullscreen", 30, 500);
	}
	else if( s++ ) {
		verdana30.drawString("My Video", 30, 100);
		s.drawVideoAt(0, 20, 200);
	}
	else if( s.subSlide(page, 3) ) {
		verdana30.drawString("Subpage " + ofToString(page), 30, 100);
		verdana30.drawString("Perhaps useful for showing vector of images", 30, 200);
	}
	else if( s++ ) {
		verdana30.drawString("And even interactive meshes...", 30, 100);
		cam.begin();
		ofRotate((float)s.getCount(), 0, 1, 0);
		plane.drawWireframe();
		cam.end();
	}
	
	s.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if( key == 'f' ) {
		ofToggleFullscreen();
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
