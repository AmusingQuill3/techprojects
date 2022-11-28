//CSIS 112 Class Composition -- 
//CSIS 112-B02

#include <iostream>
#include <string>
#include "Dealership.h"

using namespace std;

int main()
{
	//Introduction
	cout << "Elijah Bixby -- Class Composition\n\n";

	//Call on class
	Dealership d;

	//Set variables
	char Selection;
	string Name;
	int Size, Test = 0;

	//Create object
	Dealership InfoObj;

	//Give Instructions
	cout << "Enter the name of the dealership:   ";

	//Get dealership name
	cin.ignore();

	getline(cin, Name);

	//Set dealership name in object
	InfoObj.Name = Name;

	//Give Instructions
	cout << "Enter the lot capacity of the dealership:   ";

	//Get dealership size and set to object
	cin >> InfoObj.Size;

	//Call on dealership class to set variables
	d.setDealershipInfo(InfoObj);


	//Loop statement for menu navigation
	do
	{
		//Create menu
		cout << "Main Menu\n" <<
			"A - Add a new vehicle\n" <<
			"L - List vehicles\n" <<
			"Q- Quit\n" <<
			"Selection:  ";

		//Get Menu Selection
		cin >> Selection;


		//Allow selection for menu navigation
		switch (Selection) {

			//Case for add vehicle
		case 'A':
			//Check if vector is full or not
			Test = d.addVehicleTest();
			if (Test == 1)
			{
				cout << "The dealership does not have the capacity to hold more vehicles\n\n";
			}

			//If vector is not full call on add vehicle function
			else
				d.addVehicle();
			break;


			//Case to list vehicles
		case 'L':
			d.listVehicles();
			break;


			//Quit system
		case 'Q':
			system("pause");
			break;


			//Error checking
		default:
			cout << "Invalid input please try again\n";
		}


	} while (Selection != 'Q');
	//End of loop




	return 0;
}