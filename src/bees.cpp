
#include "bees.h"

bees::bees(){
    pos.y = ofGetHeight()/2;
    pos.x = ofGetWidth()/2;
    speed.x = 1;
    speed.y = -3;
    radius = 20;
    
    img.loadImage("bee.png");
    img.setAnchorPercent(.5, .5);
}




//---------------------------------------------------------------

void bees::update() {
    
    pos.x = cos(ofGetElapsedTimef()*speed.x)*(ofGetWidth()/2 - radius) + ofGetWidth()/2;
    pos.y = sin(ofGetElapsedTimef()*speed.y)*(ofGetHeight()/2 - radius) + ofGetHeight()/2;

}


//---------------------------------------------------------------

void bees::draw(){

    ofSetRectMode(OF_RECTMODE_CENTER);
    img.draw(pos.x, pos.y, radius, radius);
    
    
        
}