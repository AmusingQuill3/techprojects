#include <iostream>
#include "Insect.h"
#include "Locust.h"

using namespace std;

Locust::Locust()
{
	cout << "Invoking Locust constructor\n";
}

void LocustEat()
{
	cout << "As a locust, I eat leaves.\n\n";
}

Locust::~Locust()
{
	cout << "Invoking Locust destructor\n";
}