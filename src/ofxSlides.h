#pragma once

#include "ofMain.h"

class ofxSlides {
private:
	int turn; // increment within draw()
	int page; // current page num to display
	

public:
	ofxSlides() : turn(0), page(0) {
		enable();
	}
	
	int getPage() const;
	
	void enable();
	void disable();
	
	void update(ofEventArgs &args);
	void keyPressed(ofKeyEventArgs &args);
	void keyReleased(ofKeyEventArgs &args);
	
	void begin();
	void end();
	
	bool operator++();
	bool operator++(int);
	
	// if( s.subSlide(subPage, range) ) { ... }
	bool subSlide(int &, int);
};
