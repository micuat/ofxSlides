#include "ofxSlides.h"

int ofxSlides::getPage() const {
	return page;
}

void ofxSlides::update(ofEventArgs &args) {
}

void ofxSlides::keyPressed(ofKeyEventArgs &args) {
	
	if( args.key == OF_KEY_RIGHT ) {
		page++;
	}
	
	if( args.key == OF_KEY_LEFT ) {
		if( page > 0 ) {
			page--;
		}
	}
}

void ofxSlides::keyReleased(ofKeyEventArgs &args) {
}

void ofxSlides::enable() {
	//ofAddListener(ofEvents().update, this, &ofxSlides::update);
	ofAddListener(ofEvents().keyPressed, this, &ofxSlides::keyPressed);
	ofAddListener(ofEvents().keyReleased, this, &ofxSlides::keyReleased);
}

void ofxSlides::disable() {
	//ofRemoveListener(ofEvents().update, this, &ofxSlides::update);
	ofRemoveListener(ofEvents().keyPressed, this, &ofxSlides::keyPressed);
	ofRemoveListener(ofEvents().keyReleased, this, &ofxSlides::keyReleased);
}

void ofxSlides::begin() {
	turn = 0;
}

void ofxSlides::end() {
	// do nothing... may be useful for semaphore stuff
}

bool ofxSlides::operator++() {
	if( page == turn ) {
		turn++;
		return true;
	} else {
		turn++;
		return false;
	}
}

// same as ++s
bool ofxSlides::operator++(int) {
	if( page == turn ) {
		turn++;
		return true;
	} else {
		turn++;
		return false;
	}
}

bool ofxSlides::subSlide(int &subPage, int range) {
	if( turn <= page && page < turn + range ) {
		subPage = page - turn;
		turn += range;
		return true;
	} else {
		turn += range;
		return false;
	}
}
