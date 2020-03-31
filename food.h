#pragma once
#ifndef FOOD_H
#define FOOD_H

struct Point2f {
	float x, y;
	Point2f & operator= (const Point2f & r){
		this->x = r.x;
		this->y = r.y;
	}
};

class Food{
private:
	Point2f Pos;
	int Size_food = 3;
	float Energy = 100;	
	unsigned int lifetime;
	float R = 0;
	float G = 1;
	float B = 0;
	 
	
public:  
	Food();
	~Food();
	void drow();
	void CreatNew();
	int GetLifeTime();
	float GetEnergy();
	float GetR();
	float GetG();
	float GetB();
	Point2f GetPositionFood();
	void Aging();

};

#endif /*FOOD_H*/
