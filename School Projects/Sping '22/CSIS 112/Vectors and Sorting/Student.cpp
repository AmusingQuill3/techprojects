#include <iostream>
#include <string>
#include "Student.h"
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

	void Student::getStudentName(string StudentX)
	{
		//Set student name
		StudentName = StudentX;
	}

	void Student::getCourseName(string ClassY)
	{
		//Set course name
		CourseName = ClassY;
	}

	void Student::AddGrade(int GradeZ)
	{
		//Input grades
		grades.push_back(GradeZ);
	}

	void Student::sortVector()
	{
		//Sort grades in vector "grades"
		sort(grades.begin(), grades.end());
	}

	double Student::findMean()
	{
		//Create placeholders and variables
		double x, mean = 0;
		int i = 0;

		//Loop to grab all variables
		for (i = 1; i < grades.size(); i++)
		{
			//Add variables together
			mean = mean + grades.at(i);

			//Find amount of variables
			x = i;
		}
		
		//Calculate mean
		mean = mean / i;

		return mean;
	}

	int Student::findMax()
	{
		//Placeholders and Variables
		int i, max;
		
		//Set default value
		max = grades.at(0);

		//Grab all values
		for (i = 1; i < grades.size(); i++)
		{
			//If the value grabbed is greater than the current value for "max", "max" will be swapped out for the new value
			if (grades.at(i) > max)
				max = grades.at(i);
		}
		return max;
	}

	int Student::findMin()
	{
		//Placeholders and Variables
		int i, min;
		
		//Set default value
		min = grades.at(0);

		//Grab all values
		for (i = 1; i < grades.size(); i++)
		{
			//If the value grabbed is greater than the current value for "min", "min" will be swapped out for the new value
			if (grades.at(i) < min)
				min = grades.at(i);
		}
		return min;
	}

	int Student::getNumGrades()
	{
		//Set Variables
		int NumOfGrades;

		//Set value of the size
		NumOfGrades = grades.size();

		return NumOfGrades;
	}

	void Student::disInformation()
	{
		//Output all data by using pre-determined text as well as calling on other functions to find values
		cout << endl << getNumGrades() << " grades were recorded for this course.\n\n" <<
			"Statistics\n" <<
			"Average:" << setw(26) << fixed << setprecision(1) << findMean() <<
			"\nLowest grade:" << setw(21) << findMin() <<
			"\nHighest grade:" << setw(20) << findMax() <<
			"\n\nThe grades for " << StudentName << " - " << CourseName << " are:\n";

		//Display all sorted grades
		for (int i = 0; i < grades.size(); i++)
			cout << grades.at(i) << endl;
	}
