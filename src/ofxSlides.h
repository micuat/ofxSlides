#pragma once

#include "ofMain.h"

class ofxSlides {
private:
	int turn; // increment within draw()
	int page; // current page num to display
	int count; // for animation etc.
	int maxCount;
	float lastTurnedTime;
	enum Direction {TURNED_NEXT, TURNED_BACK, TURNED_NONE};
	Direction direction;
	
	vector<ofVideoPlayer> videos;
	vector<unsigned char> doUpdateVideo;

public:
	ofxSlides() : turn(0), page(0), count(0), maxCount(3600) {
		enable();
	}
	
	int getPage() const;
	void setPage(int);
	int getCount() const;
	float getElapsed() const;
	
	void loadVideos(string);
	ofVideoPlayer & getVideo(int);
	void drawVideoAt(int, int x = 0, int y = 0);
	
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
