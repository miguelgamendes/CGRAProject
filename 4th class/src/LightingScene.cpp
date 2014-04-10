#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "Table.h"
#include "Plane.h"
#include "Chair.h"
#include "myCylinder.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};

float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4]= {0.0,0.0,0.0,1.0};//{0.2,0.2,0.2,1.0};

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0.0, 0.8, 0.8};//{0.8, 0.8, 0.8};
float shininessA = 120.f;

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 120.f;

// Coefficients for slides material
float ambSlides[3] = {0.2, 0.2, 0.2};
float difSlides[3] = {0.8, 0.8, 0.8};
float specSlides[3] = {0.3, 0.3, 0.3};
float shininessSlides = 40.0f;

// COefficients for white board material
float ambBoard[3] = {0.2, 0.2, 0.2};
float difBoard[3] = {0.3, 0.3, 0.3};
float specBoard[3] = {0.4, 0.4, 0.4};
float shininessBoard = 80.0f;

float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};

void LightingScene::init() 
{
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Enables Flat Shading
	glShadeModel(GL_SMOOTH);

	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);  
	
	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);  
	
	// Declares and enables two lights, with null ambient component

	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setSpecular(yellow);

	//light0->disable();
	light0->enable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);
	
	//light1->disable();
	light1->enable();

	//light 2
	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	light2->setKc(0.0f);
	light2->setKl(1.0f);
	light2->setKq(0.0f);

	light2->enable();


	//light 3
	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setSpecular(yellow);
	light3->setKc(0.0f);
	light3->setKl(0.0f);
	light3->setKq(1.0f);

	light3->enable();
	
	// Uncomment below to enable normalization of lighting normal vectors
	glEnable (GL_NORMALIZE);

	//Declares scene elements
	table = new Table();
	wall = new Plane();
	chair = new Chair();
	boardA = new Plane(BOARD_A_DIVISIONS);
	boardB = new Plane(BOARD_B_DIVISIONS);
	myCyl = new myCylinder(6,5,false);
	myCyl2 = new myCylinder(6,5,true);
	
	//Declares materials
	materialA = new CGFappearance(ambA, difA, specA, shininessA);
	materialB = new CGFappearance(ambB, difB, specB, shininessB);
	slidesAppearance = new CGFappearance(ambSlides, difSlides, specSlides, shininessSlides);
	slidesAppearance->setTexture("slides.png");
	boardAppearance = new CGFappearance(ambBoard, difBoard, specBoard, shininessBoard);
	boardAppearance->setTexture("board.png");
	windowAppearance = new CGFappearance();
	windowAppearance->setTexture("window.png");
}

void LightingScene::display() 
{

	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	light0->draw();
	light1->draw();
	light2->draw();
	light3->draw();
	
	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section

	//First Table
	glPushMatrix();
		glTranslated(5,0,8);
		table->draw();
	glPopMatrix();

	//Second Table
	glPushMatrix();
		glTranslated(12,0,8);
		table->draw();
	glPopMatrix();

	//First Chair
	glPushMatrix();
		glTranslated(5,0,7);
		chair->draw();
	glPopMatrix();

	//Second Chair
	glPushMatrix();
		glTranslated(12,0,7);
		chair->draw();
	glPopMatrix();

	//Cylinder WITHOUT smooth
	glPushMatrix();
		glScaled(1.0,10.0,1.0);
		glTranslated(6,0.0,2.0);
		glRotated(-90.0, 1.0, 0.0, 0.0);
		myCyl->draw();
	glPopMatrix();

	//Cylinder WITH smooth
	glPushMatrix();
		glScaled(1.0,10.0,1.0);
		glTranslated(9,0.0,2.0);
		glRotated(-90.0, 1.0, 0.0, 0.0);
		myCyl->draw();
	glPopMatrix();

	//Floor
	glPushMatrix();
		glTranslated(7.5,0,7.5);
		glScaled(15,0.2,15);
		materialB->apply();
		wall->draw();
	glPopMatrix();

	//LeftWall
	glPushMatrix();
		glTranslated(0,4,7.5);
		glRotated(-90.0,0,0,1);
		glScaled(8,0.2,15);
		//materialB->apply();
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		wall->draw();
	glPopMatrix();

	//PlaneWall
	glPushMatrix();
		glTranslated(7.5,4,0);
		glRotated(90.0,1,0,0);
		glScaled(15,0.2,8);
		wall->draw();
	glPopMatrix();

	// Board A
	glPushMatrix();
		glTranslated(4,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		//materialA->apply();
		boardA->draw(slidesAppearance);
	glPopMatrix();
	
	//PlaneB
	glPushMatrix();
		glTranslated(10.5,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		//materialB->apply();
		boardB->draw(boardAppearance);
	glPopMatrix();
	
	// ---- END Primitive drawing section
	

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

LightingScene::~LightingScene() 
{
	delete(light0);
	delete(light1);

	delete(table);
	delete(wall);
	delete(boardA);
	delete(boardB);
	delete(materialA);
	delete(materialB);
}