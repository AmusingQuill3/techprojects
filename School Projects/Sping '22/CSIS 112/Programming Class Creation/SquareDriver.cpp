//CSIS 112 Programming Class Creation Assignment -- Create a class that gives the perimeter and area of a square using an input.
//CSIS 112-B02
#include "Square.h"
#include <iostream>
#include <string>
using namespace std;




int main()
{
	cout << ("Elijah Bixby – Programming Class Creation \n");
	
	//Declare variables
	float x;

	//Call on class
	Square s;

	//Do statement to ensure looping
	do
	{
		//Retrieve side size
		cout << "\n\nEnter Square Side\nNumber must be positive\nEnter -1 to end program\n";
		cin >> x;

		//Input Error Checking
		while (cin.fail() || x < -1)
		{
			cout << "You must enter a number that is positive\nEnter -1 to end program\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> x;
		}

		//End program if x = -1
		if (x == -1)
			return 0;

		//Call on setSide
		s.setSide(x);

		//Call on showData
		s.showData();
	} while (x != -1);
}