#pragma once

#include "ofMain.h"
#include "ofxCV.h"
#include "ofxGUI.h"
#include "ofxOpenCV.h"

class ofApp : public ofBaseApp{

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
private:
    ofImage before, after;
    
    ofxPanel gui;
    
    bool bHide;
    
    ofxIntSlider radius;
    ofxColorSlider color;
    ofxVec2Slider center;
    ofxFloatSlider circleResolution;
    ofxToggle crossed;

    ofxButton process0;
    ofxButton process1;
    ofxButton process2;
    ofxButton process3;
    ofxButton process4;
    ofxButton process5;
    ofxButton process6;
    ofxButton process7;

    ofxLabel Result;
    string str1;
    ofSoundPlayer ring;
		
    bool isCross;
    ofVec2f pos;
};
