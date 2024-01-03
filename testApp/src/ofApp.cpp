#include "ofApp.h"
#include "ofxCameraSaveLoad.h"

bool bLoadOk = false;

void ofApp::setup(){

    //
    //  Check if resource loading works
    //  We need to move this app outside folder and put it back, know as macOS's app translocation
    //  https://developer.apple.com/forums/thread/724969
    //  * only for app downloaded via Github release or action artifact
    //
    bLoadOk = ofxLoadCamera(cam, "./cameraSettings");
}

void ofApp::update(){

}

void ofApp::draw(){
    ofBackground(180);
    cam.begin();
    ofPushMatrix();
    ofRotateZDeg(90);
    ofSetColor(100);
    ofDrawGridPlane(2, 10, false);
    ofPopMatrix();
    ofSetColor(0, 0, 255);
    ofDrawBox(0, 5, 0, 3, 3, 3);
    cam.end();
    
    ofSetColor(0);
    if(bLoadOk){
        ofDrawBitmapString("OK: load cameraSettings", 5, 15);
    }else{
        ofDrawBitmapString("ERROR: Can not load cameraSettings", 5, 15);
    }
}


void ofApp::exit(){
    ofxSaveCamera(cam, "./cameraSettings");
}
