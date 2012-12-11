//USING OFXBOIDS ADD-ON


#include "testApp.h"
#include <iostream>
#include <GLUT/GLUT.h>



//--------------------------------------------------------------
void testApp::setup()
{
    
    //BOIDS ADD-ON
    
	ofBackground(255);
	ofSetFrameRate(30);
	ofSetVerticalSync(false);
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	//ofEnableNormalizedTexCoords();
	ofHideCursor();
	
	glNewList(1, GL_COMPILE);
	glutSolidSphere(1, 40, 40);
	glEndList();
	
	boidNum = 900;
	target = ofVec3f(0, 0, 0);
    
    //ADD SWARM TO HIVE BOOLEAN
    hive = 10.0;
    mouseD = false;

	for (int i = 0; i < boidNum; i++)
	{
		SteeredVehicle v(ofRandom(100)-50, ofRandom(100)-50, ofRandom(100)-50);
		v.maxForce = .5f;
        //VARIABLE CHANGED
		v.inSightDist = hive;
		boids.push_back(v);
	}
      
	
	cam.setDistance(500);
	
	GLfloat color[] = { 1.0, 0.2, 0.2 };
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
    
    //ADD HIVE IMAGE
    img.loadImage("hive.png");
    img.setAnchorPercent(.5, .5);
    
    
}

//--------------------------------------------------------------
void testApp::update()
{

    if(mouseD == false) {
        for (int i = 0; i < boidNum; i++)
            {
                boids[i].flock(boids);
                boids[i].update();
                boids[i].wrap(1000, 1000, 1000);
            }
        }

    if(mouseD == true) {
        for (int i = 0; i < boidNum; i++)
        {
            boids[i].flock(boids);
            boids[i].update();
            boids[i].wrap(20, 20, 20);
        }
    }
    
    myBee.update();
}

//--------------------------------------------------------------
void testApp::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	
	cam.begin();
	
	for (int i = 0; i < boidNum; i++)
	{
		glPushMatrix();
		glTranslatef(boids[i].position.x, boids[i].position.y, boids[i].position.z);
		
        GLfloat color[] = { 0.9, 0.9, 0.2, 1.0 };
        
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
		glCallList(1);
		glPopMatrix();
	}
	
	cam.end();
    glPushMatrix();
    img.draw((ofGetWidth()/2 + 43), (ofGetHeight()/2 + 17), 93, 78);
    glPopMatrix();
    
    myBee.draw();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    mouseD = true;

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    mouseD = false;

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}