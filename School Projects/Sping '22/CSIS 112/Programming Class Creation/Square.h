#pragma once
#include <string>

class Square
{
public:
	Square();


	void setSide(float x);


	float getSide();


	float calcPerimeter(float y);


	float calcArea(float y);


	void showData();


private:
	//Create variable
	float side;
};
