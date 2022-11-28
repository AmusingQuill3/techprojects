//CSIS 112 Polymorphism Assignment -- 
//CSIS 112-B02

#include <iostream>
#include "Insect.h"

using namespace std;

int main()
{
	//Introcution
	cout << "Elijah Bixby -- Polymorphism Assignment\n\n";

	//Create Variables
	int count = 0, selection, i;
	string order;
	double size;
	char insect;

	//Use integer 100 for srand
	srand(100);


	//Create Object
	Insect** Insects;
	Insects = (Insect**)malloc(3 * sizeof(Insect*));

	
	//Loop statement for menu navigation
	do
	{
		//Create menu
		cout <<
			"Main Menu\n\n" <<
			"1 - Ant\n\n" <<
			"2 - Locust\n\n" <<
			"3 - Butterfly\n\n" <<
			"4 - Termite\n\n" <<
			"Enter selection:   ";

		//Have user enter selection
		cin >> selection;


		//Allow selection for menu navigation
		switch (selection) {

		case 1:
			//Set insect type
			insect = 'A';

			//Set insect size
			size = ((rand() % (99 + 1)) + (1)) / 100.0;

			break;


		case 2:
			//Set insect type
			insect = 'L';

			//Set insect size
			size = ((rand() % (395 + 1)) + (105)) / 10.0;

			break;


		case 3:
			//Set insect type
			insect = 'B';

			//Set insect size
			size = ((rand() % (355 + 1)) + (400)) / 10.0;

			break;
		case 4:


			//Set insect type
			insect = 'T';

			//Set insect size
			size = ((rand() % (40 + 1)) + (15)) / 10.0;

			break;


		default:
			cout << "Invalid input please try again\n";
		}


		//Give instructions
		cout << "\nEnter the Order associated with the insect you selected:   ";

		//Get user input
		cin >> order;


		//Input data into array
		Insects[count] = new Insect(insect, order, size);


		//Count until array full
		count++;

	} while (count != 3);

	for (i = 0; i < 3; i++)
	{
		//Output array
		Insects[i]->outputInfo();
	}

	for (i = 0; i < 3; i++)
	{
		//Output array
		delete Insects[i];
	}

	return 0;
}