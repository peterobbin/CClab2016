#pragma once

#include "ofMain.h"

// STEP 6: Include the header file of ofxOpenCv
#include "ofxOpenCv.h"

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
    
    // (STEP 1 is in main.cpp.)
    // STEP 2: Member objects/variables for webcam video grabber
    ofVideoGrabber mVidGrabber;
    int mCamWidth;
    int mCamHeight;
    
    // STEP 7: Member objects/variables for openCV
    // Image storages in openCV format:
    ofxCvColorImage mColorImg;
    ofxCvGrayscaleImage mGrayImage;
    ofxCvGrayscaleImage mGrayBg;
    ofxCvGrayscaleImage mGrayDiff;
    
    // For blob detection:
    ofxCvContourFinder mContourFinder;
    
    int mThreshold; // Threshold for the difference image
    bool mLearnBackground; // Indicate whether the background image for difference needs updating
    
};
