#include <iostream>
#include <cstdlib>
#include <cctype>
#include "Date.h"

using namespace std;


Date::~Date() {}

void Date::setDate(int d, int m, int yyyy) {
	day = d;
	month = m;
	year = yyyy;
}
