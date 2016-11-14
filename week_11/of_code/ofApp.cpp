#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // STEP 3: Setup video grabber
    ofBackground(128);
    
    mCamWidth = 320;  // try to grab at this size.
    mCamHeight = 240;
    
    mVidGrabber.setDeviceID(0);
    mVidGrabber.setDesiredFrameRate(60);
    mVidGrabber.initGrabber(mCamWidth, mCamHeight);
    
    // STEP 8: Setup openCV objects/variables
    mColorImg.allocate(mCamWidth, mCamHeight);
    mGrayImage.allocate(mCamWidth, mCamHeight);
    mGrayBg.allocate(mCamWidth, mCamHeight);
    mGrayDiff.allocate(mCamWidth, mCamHeight);
    
    mThreshold = 80;
    mLearnBackground = true;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // STEP 4: Grab data from webcam
    mVidGrabber.update();
    
    // STEP 9: Computer Vision
    // Only do this when there is a new frame from webcam.
    if (mVidGrabber.isFrameNew()) {
        
        // Convert the webcam to openCV format.
        mColorImg.setFromPixels(mVidGrabber.getPixels());
        
        // Convert ofxCvColorImage to ofxCvGrayscaleImage (3 channels -> 1 channel), so that we can do math on it easily.
        mGrayImage = mColorImg;
        
        if (mLearnBackground == true){ // Need to update difference background
            mGrayBg = mGrayImage;
            mLearnBackground = false;
        }
        
        // Take the absolute value of the difference between background and current frame, and then threshold:
        mGrayDiff.absDiff(mGrayBg, mGrayImage);
        mGrayDiff.threshold(mThreshold); // Pixels that has value >= mThreshold become white (255); others become black (0).
        
        // STEP 12: Blob detection
        // Find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
        // Also, find holes is set to true so we will get interior contours as well.
        mContourFinder.findContours(mGrayDiff, 20, (340*240)/3, 10, true);
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // STEP 5: Draw webcam image
    ofSetColor(255);
    mVidGrabber.draw(20, 20);
    // (Now build and run.)
    
    // STEP 10: Draw openCV results
    mGrayImage.draw(360,20);
    mGrayBg.draw(20,280);
    mGrayDiff.draw(360,280);
    // (Now build and run.)
    
    // STEP 13: Draw detected blobs
    // First draw backgroud.
    ofFill();
    ofSetColor(0);
    ofDrawRectangle(360,540,320,240);
    ofSetColor(255);
    
    // Then draw blobs.
    mContourFinder.draw(360,540);
    
    // Now draw blobs over webcam image.
    // First draw webcam image.
    mVidGrabber.draw(20, 540);
    
    // Then draw blobs.
    // This time we draw each blob individually from the blobs vector.
    // This is how to get access to them. You can use the blob data to do interesting things.
    for (int i = 0; i < mContourFinder.nBlobs; i++){
        mContourFinder.blobs[i].draw(20,540);
        
        // Draw text over the centroid if the blob is a hole
        ofSetColor(255);
        if(mContourFinder.blobs[i].hole){
            ofDrawBitmapString("hole",
                               mContourFinder.blobs[i].boundingRect.getCenter().x + 20,
                               mContourFinder.blobs[i].boundingRect.getCenter().y + 540);
        }
    }
    // (Now build and run.)
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // Step 11: Use space key to update difference background
    // (Before, the backgroud is alway the first frame.)
    switch (key){
        case ' ':
            mLearnBackground = true;
            break;
        // Step 14: Use s key to save the snapshot image to disk.
        // The image will be save to bin/data folder in your project folder.
        case 's':
            ofImage snapshot;
            snapshot.allocate(ofGetWindowWidth(), ofGetWindowHeight(), OF_IMAGE_COLOR);
            snapshot.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
            snapshot.save("snapshot.png");
            break;
    }
    
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
