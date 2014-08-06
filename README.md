ofxSlides
========

Naoto HIÉDA <micuat@gmail.com>, 09 Feb 2014

Quick Demo Videos
--------

Sequential drawing example: <http://instagram.com/p/qxXSwWAT34>

`example_simple` (presentation example): <http://www.youtube.com/watch?v=U0DnBADky6I>


About
--------

This is originally a helper addon for making presentation slides using openFrameworks but turned out to be useful for any sequential drawing, for example:

```
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
		
		if( s.getElapsed() > 2.f ) s.proceed();
	}
	else if( s++ ) {
		color.setHsb(0, 255, 255, ofMap(s.getElapsed(), 0, 1, 0, 255, true));
		ofSetColor(color);
		ofDrawBox(0, ofMap(s.getElapsed(), 0, 1, 0, 100, true), 0, 200);
		
		color.setHsb(0, 255, 255, ofMap(s.getElapsed(), 0, 1, 255, 0, true));
		ofSetColor(color);
		ofNoFill();
		ofDrawBox(0, ofMap(s.getElapsed(), 0, 1, 0, 100, true), 0, 200);
		
		if( s.getElapsed() > 1.f ) s.proceed();
	}
	else if( s++ ) {
		color.setHsb(ofMap(s.getElapsed(), 0, 1, 0, 100, true), 255, 255);
		ofSetColor(color);
		ofDrawBox(ofMap(s.getElapsed(), 0, 1, 0, 100, true), 100, 0, 200);
		
		if( s.getElapsed() > 1.f ) s.proceed();
	}
	else if( s++ ) {
		color.setHsb(ofMap(s.getElapsed(), 0, 1, 100, 200, true), 255, 255);
		ofSetColor(color);
		ofDrawBox(100, ofMap(s.getElapsed(), 0, 1, 100, 0, true), 0, 200);
	}
	cam.end();
	
	s.end();
}
```


Usage
--------

See `example_simple`.
