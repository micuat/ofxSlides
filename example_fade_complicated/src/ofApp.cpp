#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	int count = 0;
	
	ofxSVG svg;
	svg.load(ofToDataPath("ill.svg"));
	for( int i = 0; i < svg.getNumPath(); i++ ) {
		ofPath p = svg.getPathAt(i);
		// svg defaults to non zero winding which doesn't look so good as contours
		p.setPolyWindingMode(OF_POLY_WINDING_ODD);
		vector<ofPolyline>& lines = p.getOutline();
		for(int j=0;j<(int)lines.size();j++){
			polylines.push_back(lines[j].getResampledBySpacing(3));
			for( int k = 0; k < polylines[polylines.size()-1].size(); k += 5 ) {
				count++;
			}
			for( int k = 0; k < polylines[polylines.size()-1].size(); k ++ ) {
				polylines[polylines.size()-1].getVertices().at(k).y *= -1;
				polylines[polylines.size()-1].getVertices().at(k) -= ofVec2f(50, -100);
				polylines[polylines.size()-1].getVertices().at(k) *= 3;
			}
		}
	}
	
	mesh.setMode(OF_PRIMITIVE_POINTS);
	float amp = 200;
	for( int i = 0; i < count; i++ ) {
		mesh.addVertex(ofVec3f(ofRandom(amp*2) - amp, ofRandom(amp*2) - amp, ofRandom(amp*2) - amp));
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(104, 255);
	
	s.begin();
	
	//ofRotate(ofMap(ofGetElapsedTimef(), 0, 2, 0, 360), 0, 1, 0);
	ofColor color;
	ofFill();
	
	if( s++ ) {
		ofNoFill();
		cam.begin();
		
//		ofPushMatrix();
//		ofTranslate(5*(ofGetElapsedTimef() * 2 - (long)(ofGetElapsedTimef() * 2)), 0, 0);
//		ofSetColor(ofColor::paleVioletRed);
//		for (int i = 0; i < (int)polylines.size(); i++){
//			ofPolyline & line = polylines[i];
//			
//			line.draw();
//		}
//		ofPopMatrix();
//		
//		ofPushMatrix();
//		ofTranslate(-5*(ofGetElapsedTimef() * 2 - (long)(ofGetElapsedTimef() * 2)), 0, 0);
//		ofSetColor(ofColor::mintCream);
//		for (int i = 0; i < (int)polylines.size(); i++){
//			ofPolyline & line = polylines[i];
//			
//			line.draw();
//		}
//		ofPopMatrix();
		
		color = ofColor(0, 128);
		ofSetColor(color);
		for (int i = 0; i < (int)polylines.size(); i++){
			ofPolyline & line = polylines[i];
			
			line.draw();
		}
		cam.end();
	}
	else if( s++ ) {
		ofSetLineWidth(ofMap(s.getElapsed(), 0, 2, 2, 1, true));
		color = ofColor(0, 128);
		color.lerp(ofColor::red, ofClamp(s.getElapsed(), 0, 1));
		ofSetColor(color);
		drawPoints(1, true);
	}
	else if( s++ ) {
		color.setHsb(ofMap(s.getElapsed(), 0, 1, 0, 100, true), 255, 255);
		ofSetColor(color);
		drawPoints(ofMap(s.getElapsed(), 0, 1, 1, 3, true), false);
	}
	else if( s++ ) {
		color.setHsb(ofMap(s.getElapsed(), 0, 1, 100, 200, true), 255, 255);
		ofSetColor(color);
		drawPoints(ofMap(s.getElapsed(), 0, 3, 3, 0, true), false);
	}
	
	s.end();
}

//--------------------------------------------------------------
void ofApp::drawPoints(float amp, bool transform){
	cam.begin();
	ofNoFill();
	ofSetPolyMode(OF_POLY_WINDING_ODD);
	ofBeginShape();
	
	float p = ofClamp(1 - s.getElapsed() / 2, 0, 1);
	int i = 0;
	for (int j = 0; j < (int)polylines.size(); j++){
		ofPolyline & line = polylines[j];
		for( int k = 0; k < line.getVertices().size(); k+=5 ) {
			ofVec3f v = mesh.getVertex(i);
			ofVec3f vv;
			v.x += 10 * ofNoise(ofGetElapsedTimef(), i, mouseX);
			v.y += 10 * ofNoise(ofGetElapsedTimef() * 2, i, mouseY);
			v.z += 10 * ofNoise(ofGetElapsedTimef() * 3, i, mouseX);
			v *= amp * ofNoise(ofGetElapsedTimef() * 2, i);
			
			vv = v;
			
			if( transform ) {
				vv = v.getInterpolated(line.getVertices().at(k), p);
			}
			ofCurveVertex(vv.x, vv.y, vv.z);
			
			i++;
		}
	}
	
	ofEndShape(false);
	cam.end();
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
