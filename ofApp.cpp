#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//Upload cat pictures
	godCat1.load("images/godCat1.GIF");
	godCat2.load("images/godCat2.GIF");
	godCat4.load("images/godCat4.GIF");


	ofSoundStreamSetup(0, 1, this, 48000, beat.getBufferSize(), 4);
}

//--------------------------------------------------------------
void ofApp::update(){
	beat.update(ofGetElapsedTimeMillis());
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Resize cat pictures to be entire window
	godCat1.resize(ofGetWindowWidth(), ofGetWindowHeight());
	godCat2.resize(ofGetWindowWidth(), ofGetWindowHeight());
	godCat4.resize(ofGetWindowWidth(), ofGetWindowHeight());

	// Check beat detecter and place a different image depending if a snare, kick, or no beat is detected. There are
	// a lot of if statements attempting to smooth the picture transitions by making them stay for longer
	if((beat.isKick() || iterKick>0) && iterSnare ==0 && iterNoBeat ==0){
		godCat4.draw(0, 0);
		if (beat.isKick()) {
			iterKick = 40;
		}
	}
	else if (beat.isSnare()  || iterSnare>0 && iterNoBeat==0) {
		godCat2.draw(0, 0);
		if (beat.isSnare()) {
			iterSnare = 40;
		}
	}
	else {
		godCat1.draw(0, 0);
		if (iterNoBeat == 0) {
			iterNoBeat = 30;
		}
	}

	if (iterKick > 0) {
		iterKick--;
	}
	else {
		iterKick = 0;
	}

	if (iterSnare > 0) {
		iterSnare--;
	}
	else {
		iterSnare = 0;
	}

	if (iterNoBeat > 0) {
		iterNoBeat--;
	}
	else {
		iterNoBeat = 0;
	}
}

//--------------------------------------------------------------
void ofApp::audioReceived(float* input, int bufferSize, int nChannels) {
	beat.audioReceived(input, bufferSize, nChannels);
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
