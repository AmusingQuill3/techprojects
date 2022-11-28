#include <iostream>
#include "Insect.h"
#include "Ant.h"

using namespace std;

Ant::Ant()
{
	cout << "Invoking Ant destructor\n";
}

void AntEat()
{
	cout << "As an ant, I eat everything.\n\n";
}

Ant::~Ant()
{
	cout << "Invoking Ant destructor\n";
}