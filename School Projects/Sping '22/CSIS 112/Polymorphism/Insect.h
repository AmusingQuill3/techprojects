#pragma once
#include <iostream>

class Insect
{
public:

	Insect();

	Insect(char iinsect, std::string iorder, double isize);

	void Eat();

	void outputInfo();

	~Insect();

private:
	std::string order;
	double size;
	char insect;
};