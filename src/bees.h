
#ifndef BEES_H
#define BEES_H

#include "ofMain.h"

class bees {
    
public:
    bees();
    void update();
    void draw();
    
    ofPoint pos;
    ofPoint speed;
    float radius;
    
    ofImage img;
    
};

#endif