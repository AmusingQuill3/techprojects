#include <iostream>
#include "Insect.h"
#include "Termite.h"

using namespace std;

Termite::Termite()
{
	cout << "Invoking Termite constructor\n";
}

void TermiteEat()
{
	cout << "As a Termite, I eat wood.\n\n";
}

Termite::~Termite()
{
	cout << "Invoking Termite destructor\n";
}