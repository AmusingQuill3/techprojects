#include <iostream>
#include "Insect.h"
#include "Ant.h"
#include "Locust.h"
#include "Butterfly.h"
#include "Termite.h"

using namespace std;

Ant a;
Locust l;
Butterfly b;
Termite t;

Insect::Insect()
{
	//Default constructor
	size = 0;

	cout << "Invoking the default Insect constructor\n";
}

Insect::Insect(char iinsect, std::string iorder, double isize)
{
	//Set values
	insect = iinsect;

	order = iorder;

	size = isize;

	cout << "\nInvoking the 2-argument Insect constructor.\n\n";
}

void Insect::Eat()
{
	cout << "This is a virtual function\n";
}

void Insect::outputInfo()
{
	cout << "\nMy Order is " << order << ", and I am " << size << "millimeters long.\n";

	switch (insect) {
	case 'A':
		cout << "As an ant, I eat everything.\n\n";
		break;
	case 'L':
		cout << "As a locust, I eat leaves.\n\n";
		break;
	case 'B':
		cout << "As a butterfly, I eat nectar.\n\n";
		break;
	case 'T':
		cout << "As a Termite, I eat wood.\n\n";
		break;
	}

}

Insect::~Insect()
{
	//Destructor
	cout << "Invoking the default Insect destructor.\n";
}