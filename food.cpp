/*

	g++ Name.cpp -lglut -lGL -o Name

*/
#include <cmath>
#include <iostream>
#include <GL/glut.h>
#include <fstream> // fsream ofsrteam ifstream
#include <ctime>
#include <string>
#include "food.h"

using namespace std;



//___FOOD_______________________________________________________________________
Food::Food(){
	CreatNew();
}	
Food::~Food(){
	//cout << "Dead" << endl;
}
//___CREAT NEW__________________________________________________________________
void Food::CreatNew(){
	R = B = 0;
	G = 1;
	this->Pos.x = rand()%1000;
	this->Pos.y = rand()%1000;
	this->lifetime += 150 + rand()%90;
}
//___DROW_______________________________________________________________________
void Food::drow(){		
	glBegin(GL_LINE_LOOP);
		glColor3f(R,G,B);
		for(int j=0; j < 36; ++j){
			glVertex2f(this->Pos.x + Size_food*cos(M_PI*2*j/36), this->Pos.y+Size_food*sin(M_PI*2*j/36));
		}
	glEnd();
}
//___Get LIFETIME_______________________________________________________________
int Food::GetLifeTime(){
	return this->lifetime;
}
//___GET ENERGY ________________________________________________________________
float Food::GetEnergy(){
	return this->Energy;
}
//___GET POSITION FOOD__________________________________________________________
Point2f Food::GetPositionFood(){
	return this->Pos;
}
//___GET R______________________________________________________________________
float Food::GetR(){
	return this->R;
}
//___GET G______________________________________________________________________
float Food::GetG(){
	return this->G;
}
//___GET B______________________________________________________________________
float Food::GetB(){
	return this->B;
}
//___AGING______________________________________________________________________
void Food::Aging(){
	--this->lifetime;
	if(lifetime > 150/2){
		R = 0;
		G = 1;
		B = 0;
	}
	else if(lifetime > 150/4 && lifetime < 150/2){
		R = 1;
		G = 1;
		B = 0;
	}
	else if(lifetime > 0 && lifetime < 150/4){
		R = 1;
		G = 0;
		B = 0;
	}
	else if(lifetime <= 0){
		CreatNew();
	}
		//cout << this->lifetime << "\t" <<  this->R << "\t" <<  this->G << endl;
}













