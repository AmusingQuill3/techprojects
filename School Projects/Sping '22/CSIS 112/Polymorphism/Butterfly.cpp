#include <iostream>
#include "Insect.h"
#include "Butterfly.h"

using namespace std;

Butterfly::Butterfly()
{
	cout << "Invoking Butterfly constructor\n";
}

void ButterflyEat()
{
	cout << "As a butterfly, I eat nectar.\n\n";
}

Butterfly::~Butterfly()
{
	cout << "Invoking Butterfly destructor\n";
}