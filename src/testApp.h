#pragma once

#include "ofMain.h"
#include "ofxBoids.h"
#include "bees.h"

class testApp : public ofBaseApp{

    //BOIDS
	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	
	ofEasyCam cam;
	
	int boidNum;
	ofVec3f target;
	vector<SteeredVehicle> boids;
    
    //Bees
    bees myBee;
    bees anotherBee;
    
    //HIVE
    float hive;
    Boolean mouseD;
    ofImage img;
};
