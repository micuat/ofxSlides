#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(54, 54, 54, 255);
	
	s.begin();
	
	cam.begin();
	ofRotate(ofMap(ofGetElapsedTimef(), 0, 2, 0, 360), 0, 1, 0);
	ofColor color;
	ofFill();
	
	if( s++ ) {
		ofNoFill();
		color.setHsb(0, 255, 255, 255);
		ofSetColor(color);
		ofDrawBox(0, 0, 0, 200);
	}
	else if( s++ ) {
		color.setHsb(0, 255, 255, ofMap(s.getElapsed(), 0, 1, 0, 255, true));
		ofSetColor(color);
		ofDrawBox(0, ofMap(s.getElapsed(), 0, 1, 0, 100, true), 0, 200);
		
		color.setHsb(0, 255, 255, ofMap(s.getElapsed(), 0, 1, 255, 0, true));
		ofSetColor(color);
		ofNoFill();
		ofDrawBox(0, ofMap(s.getElapsed(), 0, 1, 0, 100, true), 0, 200);
	}
	else if( s++ ) {
		color.setHsb(ofMap(s.getElapsed(), 0, 1, 0, 100, true), 255, 255);
		ofSetColor(color);
		ofDrawBox(ofMap(s.getElapsed(), 0, 1, 0, 100, true), 100, 0, 200);
	}
	else if( s++ ) {
		color.setHsb(ofMap(s.getElapsed(), 0, 1, 100, 200, true), 255, 255);
		ofSetColor(color);
		ofDrawBox(100, ofMap(s.getElapsed(), 0, 1, 100, 0, true), 0, 200);
	}
	cam.end();
	
	s.end();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
