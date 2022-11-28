#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

// Now all the standard names that we use
using std::cout;
using std::endl;
using std::string;
using std::ostream;

const int defaultSize = 10;

// Return true iff "x" is even
inline bool EVEN(int x) { return (x % 2) == 0; }

// Return true iff "x" is odd
inline bool ODD(int x) { return (x % 2) != 0; }

void Assert(bool val, string s) {
	if (!val) {
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}

// Swap two elements in a generic array
template<typename E>
inline void swap(E A[], int i, int j) {
	E temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
// Random number generator functions

inline void Randomize()
{
	srand(1);
}

// Return a random value in range 0 to n-1
inline int Random(int n)
{
	return rand() % (n);
}


// Swap two integers
inline void swap(int& i, int& j) {
	int temp = i;
	i = j;
	j = temp;
}

// Swap two char*'s
inline void swap(char* i, char* j) {
	char* temp = i;
	i = j;
	j = temp;
}


// Big enough for simple testing
#define INFINITY 9999

// Timing variables and functions
unsigned tstart = 0;

// Initialize the program timer
void Settime() { tstart = (unsigned)clock(); }

// Return the elapsed time since the last call to Settime
double Gettime() {
	unsigned tcurr = (unsigned)clock();
	return (double)(tcurr - tstart) / (double)CLOCKS_PER_SEC;
}

class Int {
private:
	int val;
public:
	Int(int input = 0) { val = input; }

	int key() const { return val; }
	Int operator= (int input) { val = input; return val; }
};

// Let us print out Ints easily
ostream& operator<<(ostream& s, const Int& i)
{
	return s << i.key();
}
ostream& operator<<(ostream& s, const Int* i)
{
	return s << i->key();
}

#endif
