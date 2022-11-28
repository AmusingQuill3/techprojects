//CSIS 112 Inheritance and Operator Overloading -- 
//CSIS 112-B02

#include <iostream>
#include <string>
#include "Course.h"
#include "Person.h"

using namespace std;

int main()
{
	//Introduction
	cout << "Elijah Bixby -- Inheritance and Operator Overloading\n\n";

	//Declare Variables
	string courseName;
	int maxcap;
	char Selection;

	//Call on class
	Course c;



	//Retrieve coursename
	cout << "Enter a name for your Course:  ";
	cin.ignore();
	getline(cin, courseName);

	//Retrieve course maximum capacity
	cout << "What is the maximum capacity for your Course?  ";
	cin >> maxcap;

	//Set course name and capacity within Course Class
	c.setcourseInfo(courseName, maxcap);


	//Loop statement for menu navigation
	do
	{
		//Create menu
		cout <<
			"\n\n                Main Menu\n" <<
			"        I -- Add Instructor\n" <<
			"        S -- Add Student\n" <<
			"        L -- List Course Information\n" <<
			"        Q -- Quit\n\n\n\n" <<
			"        Selection:  ";

		//Get Menu Selection
		cin >> Selection;



		//Allow selection for menu navigation
		switch (Selection) {

			//Case to add instructor
		case 'I':
			c.addFaculty();
			break;


			//Case to add student
		case 'S':
			c.addStudent();
			break;


			//Case to list course information
		case 'L':
			//Call on Course list information
			c.listInformation();
			break;


			//Case to quit system
		case'Q':
			system("pause");
			break;


			//Error checking
		default:
			cout << "Invalid input please try again\n";
		}


	} while (Selection != 'Q');



	return 0;
}