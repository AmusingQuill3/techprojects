#include <iostream>
#include <string>
#include "Square.h"

using namespace std;

	Square::Square()
	{
		//Set Variable
		side = 0;
	}


	void Square::setSide(float x)
	{
		//Set Variable Based on Input
		side = x;
	}


	float Square::getSide()
	{
		//Send data to prevent direct access to side variable
		return side;
	}


	float Square::calcPerimeter(float y)
	{
		//Calculate Perimeter
		y = y * 4;

		return y;
	}


	float Square::calcArea(float y)
	{
		//Calculate Area
		y = y * y;

		return y;
	}


	void Square::showData()
	{
		//Output Perimeter and Area
		float y;

		y = getSide();
		
		cout << "The Perimeter is " << calcPerimeter(y) << "\nThe Area is " << calcArea(y);
	}