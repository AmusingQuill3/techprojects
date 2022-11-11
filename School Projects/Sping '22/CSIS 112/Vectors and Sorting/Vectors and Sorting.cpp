//CSIS 112 Vectors and Sorting Assignment -- Get and display course information based on file input.
//CSIS 112-B02
//
#include <iostream>
#include <string>
#include "Student.h"
#include <fstream>

using namespace std;

int main()
{
	//Introduction
	cout << "Elijah Bixby -- Vectors and Sorting\n\n";
	


	//Create Placeholder Variables
	string StudentX, ClassY, Z, FileName, placeholder;
	int GradeZ, num = 0;

	//call on class
	Student s;

	//Create fstream
	ifstream CourseFile;



	//Give Input Information
	cout << "Enter the name of the file: ";

	//Get File Name
	getline(cin, FileName);

	//Open file based off of name input
	CourseFile.open(FileName);
	
	//Redo
	while (!CourseFile)
	{
		cout << "File did not open please try again";
		
		//Get File Name
		getline(cin, FileName);

		//Open file based off of name input
		CourseFile.open(FileName);
	}

	//Read first line for student name
	getline(CourseFile, StudentX);
	//Call on class to set variable
	s.getStudentName(StudentX);

	//Read second line for class name
	getline(CourseFile, ClassY);
	//Call on class to set variable
	s.getCourseName(ClassY);



	//Ensure all values are positive
	while (CourseFile.eof() && num >= 0)
	{
		//Get Input to Test
		CourseFile >> num;

		//Find if fail was due to non-numeric value
		if (CourseFile.fail() && !CourseFile.eof())
		{
			//Explain to user non-numeric value was found
			cout << "A non-numeric value was found in the grade section... Exiting program";
			system("pause");
		}

		//Find if any negative values exist
		if (num < 0)
		{
			//Notify user negative value was found
			cout << "A negative value was found in the grade section... Exiting program";
			system("pause");
		}
	}



	//Read remaining lines for grades
	while (getline(CourseFile, Z))
	{
		//Convert string to int
		GradeZ = stoi(Z);
		s.AddGrade(GradeZ);
	}

	//Sort Vector
	s.sortVector();

	//Display Information
	s.disInformation();

	system("pause");
	return 0;
}