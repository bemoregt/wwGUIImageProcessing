#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    
    // Panel
    gui.setup(); // most of the time you don't need a name
    // ofxToggle
    gui.add(crossed.setup("Cross hair", true));
    // ofxIntSlider
    gui.add(radius.setup("Kernel Size", 0, 1, 10));
    // ofxVectorSlider: multi value
    gui.add(center.setup("Zoom", ofVec2f(ofGetWidth()*.5, ofGetHeight()*.5), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    // color slider
    gui.add(color.setup("Color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
    
    // ofxButton
    gui.add(process0.setup("Original"));
    gui.add(process1.setup("Image Flip"));
    gui.add(process2.setup("Gaussian Blur"));
    gui.add(process3.setup("Negitive"));
    gui.add(process4.setup("Sobel Edge"));
    gui.add(process5.setup("Resize"));

    // ofxLabel
    str1= "OK";
    gui.add(Result.setup("Status", "0, 0"));
    
    bHide = false;
    
    // resource
    ring.load("/Users/mun/Desktop/ring.wav");
    before.load("/Users/mun/Desktop/lena512.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackgroundGradient(ofColor::white, ofColor::gray);
    
    if(crossed){
        //before.update();
        ofDrawLine(pos.x, 1, pos.x, ofGetHeight());
        ofDrawLine(1, pos.y, ofGetWidth(), pos.y);
    }else{
        //before.update();
    }
    
    ofSetColor(color);
    //original
    if(process0){
        before.update();
        after.clear();
        ofSetColor(255);
        before.draw(0,0, 512, 512);
    }else{
        ofSetColor(255);
        before.draw(0,0, 512, 512);
    }
    //flip
    if(process1){
        Mat aa= toCv(before);
        Mat bb;
        cv::flip(aa, bb, 1);
        toOf(bb, after);
        after.update();

    }else{
        ofSetColor(255);
        after.draw(0,0, 512, 512);
    }
    // blur
    if(process2){
        Mat aa= toCv(before);
        Mat bb;
        cv::GaussianBlur(aa, bb, cv::Size(radius*2+1, radius*2+1), 2.5);
        toOf(bb, after);
        after.update();

    }else{
        ofSetColor(255);
        after.draw(0,0, 512, 512);
    }
    // negative
    if(process3){
        //before.draw(10,10,256, 256);
        Mat aa= toCv(before);
        Mat bb;
        bb= cv::Scalar::all(255) - aa;
        toOf(bb, after);
        after.update();

    }
    // sobel
    if(process4){
        //before.draw(10,10,256, 256);
        Mat aa= toCv(before);
        Mat bb;
        cv::Sobel(aa, bb, CV_8U, 5, 5);
        toOf(bb, after);
        after.update();

    }
    //
    // resize
    if(process5){
        //before.draw(10,10,256, 256);
        Mat aa= toCv(before);
        Mat bb;
        cv::resize(aa, bb, cv::Size(128, 128));
        toOf(bb, after);
        after.update();

    }
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 'h'){
        bHide = !bHide;
    }
    else if(key == 's'){
        gui.saveToFile("settings.xml");
    }
    else if(key == 'l'){
        gui.loadFromFile("settings.xml");
    }
    else if(key == ' '){
        color = ofColor(255);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    Result.setup("Mouse Pos", ofToString(x)+" , "+ofToString(y));
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
