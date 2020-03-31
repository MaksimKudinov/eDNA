/*

	g++ Name.cpp -lglut -lGL -o Name

*/
#include <cmath>
#include <GL/glut.h>
#include <iostream>
#include <fstream> // fsream ofsrteam ifstream
#include <vector>
#include <ctime>
#include <string>
#include "food.h"

using namespace std;



int W_screen = 1000;
int H_screen = 1000;

const int DELTA_T = 1E+3; // micro seconds

void display();
void timer (int = 0);

const int N = 95;

Food food[N];

int main(int argc, char** argv){

	srand(time(NULL));	
	
	
	glutInit(&argc, argv);
	glutInitDisplayMode(/*GLUT_SINGLE */ GLUT_DOUBLE | GLUT_RGB); // единичный буфер | 24-bit цвет
	glutInitWindowSize(W_screen ,H_screen );  // размер окна
	glutInitWindowPosition(380, 300); // позиция окна
	glutCreateWindow("World_v:0.1");  // название окна

	glClearColor(0.05, 0.05, 0.05, 1.0);
	glMatrixMode(GL_PROJECTION); // Выбор матрицы проекций
	glLoadIdentity(); // Сброс матрицы проекции, приводит матрицу в I виду


	//glFrustum();
	//glMatrixMode(GL_MODELVIEW);
	glOrtho(0, W_screen, 0, H_screen, -1, 1); // left, right, button, top, near, far
	glutDisplayFunc(display);
	timer();
	glutMainLoop();

}

void display(){

	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for(int i=0; i<N; i++)
		food[i].drow();
	glutSwapBuffers();

}

void timer (int){
	
	for(int i=0; i<DELTA_T/1E+6; ++i){

		for(int i=0; i<N; i++){
			if(food[i].GetLifeTime() > 0){
				food[i].Aging();			
			}
			else{}
			
		}		
	}
	display();
	glutTimerFunc(1, timer, 0);
}
















