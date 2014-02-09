#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
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
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
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
void testApp::keyPressed(int key){
	if( key == 'f' ) {
		ofToggleFullscreen();
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
