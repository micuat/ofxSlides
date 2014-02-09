#include "ofxSlides.h"

int ofxSlides::getPage() const {
	return page;
}

void ofxSlides::setPage(int _page) {
	page = _page;
}

int ofxSlides::getCount() const {
	return count;
}

void ofxSlides::loadVideos(string path) {
	ofDirectory dir;
	dir.listDir(path);
	dir.sort();
	
	if( dir.size() ){
		videos.assign(dir.size(), ofVideoPlayer());
		doUpdateVideo.assign(dir.size(), 0);
	}
	
	for( int i = 0 ; i < (int)dir.size(); i++ ) {
		videos.at(i).loadMovie(dir.getPath(i));
	}
}

ofVideoPlayer & ofxSlides::getVideo(int i) {
	return videos.at(i);
}

void ofxSlides::drawVideoAt(int i, int x, int y) {
	assert( 0 <= i && i < videos.size() );
	
	if( doUpdateVideo.at(i) == 0 ) {
		doUpdateVideo.at(i) = 1;
		videos.at(i).play();
	}
	videos.at(i).draw(x, y);
}

void ofxSlides::update(ofEventArgs &args) {
	count++;
	count %= maxCount;
	
	// update displayed videos
	for( int i = 0; i < doUpdateVideo.size() ; i++ ) {
		if( doUpdateVideo.at(i) > 0 ) {
			videos.at(i).update();
		}
	}
}

void ofxSlides::keyPressed(ofKeyEventArgs &args) {
	if( args.key == OF_KEY_RIGHT || args.key == OF_KEY_LEFT ) {
		count = 0;
		
		// refresh video update flags
		for( int i = 0; i < doUpdateVideo.size() ; i++ ) {
			if( doUpdateVideo.at(i) > 0 ) {
				doUpdateVideo.at(i) = 0;
				videos.at(i).stop();
				videos.at(i).setFrame(0);
			}
		}
	}
	
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
