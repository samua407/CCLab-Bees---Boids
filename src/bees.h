
#ifndef BEES_H
#define BEES_H

#include "ofMain.h"

class bees {
    
public:
    bees();
    void update();
    void draw();
    void mouseMoved(int x, int y );

    ofPoint pos;
    ofPoint speed;
    float radius;
    
    ofImage img;
    
    int beesX;
    int beesY;
    
    int mx,my;
    
};

#endif