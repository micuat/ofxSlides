#include "ofxSlides.h"

int ofxSlides::getPage() const {
	return page;
}

void ofxSlides::setPage(int _page) {
	page = _page;
	lastTurnedTime = ofGetElapsedTimef();
}

void ofxSlides::proceed() {
	setPage(page + 1);
}

int ofxSlides::getCount() const {
	return count;
}

float ofxSlides::getElapsed() const {
//	if( direction == TURNED_NONE ) return 0;
	return ofGetElapsedTimef() - lastTurnedTime;

//	else if( direction == TURNED_NEXT )
//		return ofGetElapsedTimef() - lastTurnedTime;
//	else if( direction == TURNED_BACK )
//		return 1-(ofGetElapsedTimef() - lastTurnedTime);
}

void ofxSlides::loadVideos(string path) {
	ofDirectory dir;
	dir.listDir(path);
	dir.sort();
	
	for( int i = 0 ; i < (int)dir.size(); i++ ) {
		videos.insert(pair<string,ofVideoPlayer>(dir.getName(i),ofVideoPlayer()));
		videos.at(dir.getName(i)).loadMovie(dir.getPath(i));
		doUpdateVideo.insert(pair<string,unsigned char>(dir.getName(i),0));
	}
}

ofVideoPlayer & ofxSlides::getVideo(string s) {
	return videos.at(s);
}

void ofxSlides::drawVideoAt(string s, int x, int y) {
	if( doUpdateVideo.at(s) == 0 ) {
		doUpdateVideo.at(s) = 1;
		videos.at(s).play();
		videos.at(s).update();
	}
	videos.at(s).draw(x, y);
}

void ofxSlides::update(ofEventArgs &args) {
	count++;
	count %= maxCount;
	
	// update displayed videos
	typedef map<string, ofVideoPlayer>::iterator it_type;
	for(it_type iterator = videos.begin(); iterator != videos.end(); iterator++) {
		if( doUpdateVideo.at(iterator->first) > 0 ) {
			iterator->second.update();
		}
	}
}

void ofxSlides::keyPressed(ofKeyEventArgs &args) {
	if( args.key == OF_KEY_RIGHT || args.key == OF_KEY_LEFT ) {
		count = 0;
		lastTurnedTime = ofGetElapsedTimef();
		
		// refresh video update flags
		typedef map<string, ofVideoPlayer>::iterator it_type;
		for(it_type iterator = videos.begin(); iterator != videos.end(); iterator++) {
			if( doUpdateVideo.at(iterator->first) > 0 ) {
				doUpdateVideo.at(iterator->first) = 0;
				iterator->second.stop();
				iterator->second.setFrame(0);
			}
		}
	}
	
	if( args.key == OF_KEY_RIGHT ) {
		page++;
		direction = TURNED_NEXT;
	}
	
	if( args.key == OF_KEY_LEFT ) {
		if( page > 0 ) {
			page--;
			direction = TURNED_BACK;
		}
	}
}

void ofxSlides::keyReleased(ofKeyEventArgs &args) {
}

void ofxSlides::enable() {
	lastTurnedTime = ofGetElapsedTimef();
	direction = TURNED_NONE;
	
	ofAddListener(ofEvents().update, this, &ofxSlides::update);
	ofAddListener(ofEvents().keyPressed, this, &ofxSlides::keyPressed);
	ofAddListener(ofEvents().keyReleased, this, &ofxSlides::keyReleased);
}

void ofxSlides::disable() {
	ofRemoveListener(ofEvents().update, this, &ofxSlides::update);
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
