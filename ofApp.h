#pragma once

#include "ofMain.h"
#include "ofxBeat.h"
#include "ofxFft.h"



class ofApp : public ofBaseApp{

	// Beat Tracking Object
	ofxBeat beat;

	private:

		//Images of cats
		ofImage godCat1;
		ofImage godCat2;
		ofImage godCat4;

		// Beat Counters for smoothing the images
		int iterKick = 0;
		int iterSnare = 0;
		int iterNoBeat = 0;


	public:


		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		

		void audioReceived(float*, int, int);
};
