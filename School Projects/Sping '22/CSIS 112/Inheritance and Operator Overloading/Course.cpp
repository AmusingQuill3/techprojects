#include <iostream>
#include <vector>
#include "Course.h"
#include "Faculty.h"
#include "Student.h"
#include "Person.h"

using namespace std;


Course::Course()
{
	capacity = 0;
}

void Course::setcourseInfo(std::string name, int maxcap)
{
	//Set course name and capacity
	courseName = name;
	capacity = maxcap;
}

void Course::addFaculty()
{
	//Create temp variables
	string ID, fName, lName, Birthdate, Title, Rank, employDate;
	double salary;

	//Get ID
	cout << "            Create Faculty Member\n" << "\nID:   ";
	cin >> ID;

	//Get First Name
	cout << "First Name:   ";
	cin >> fName;

	//Get Last Name
	cout << "Last Name:   ";
	cin >> lName;

	//Get Birthdate
	cout << "Birthdate (mm/dd/yyyy):   ";
	cin >> Birthdate;

	//Get Title
	cout << "Title:   ";
	cin >> Title;

	//Get Rank
	cout << "Rank:   ";
	cin >> Rank;

	//Get Salary
	cout << "Salary:   ";
	cin >> salary;

	//Get DoH
	cout << "Date of Hire:   ";
	cin >> employDate;

	//Set variables
	f.ID = ID;
	f.fName = fName;
	f.lName = lName;
	f.Birthdate = Birthdate;
	f.Title = Title;
	f.Rank = Rank;
	f.DateHired = employDate;
	f.Salary = salary;
}

void Course::addStudent()
{
	if (i > capacity)
	{
		cout << "\nThe class is full. No more students can be added.\n";
		return;
	}

	//Create temp variables
	string ID, fName, lName, Birthdate, Major, Level, enrolledDate;
	double GPA;

	//Get ID
	cout << "            Create Student\n\n" << "ID:   ";
	cin >> ID;

	//Get First Name
	cout << "First Name:   ";
	cin >> fName;

	//Get Last Name
	cout << "Last Name:   ";
	cin >> lName;

	//Get Birthdate
	cout << "Birthdate (mm/dd/yyyy):   ";
	cin >> Birthdate;

	//Get Major
	cout << "Major:   ";
	cin >> Major;

	//Get Level
	cout << "Level (Freshman, Sophomore, Junior, Senior):   ";
	cin >> Level;

	//Get GPA
	cout << "GPA:   ";
	cin >> GPA;

	//Get DoE
	cout << "Date of Enrollment:   ";
	cin >> enrolledDate;

	//Create Object
	Student* obj = new Student(ID, fName, lName, Birthdate, Major, Level, enrolledDate, GPA);

	//Place object in vector
	students.push_back(*obj);


	//Set variables
	object.ID = ID;
	object.fName = fName;
	object.lName = lName;
	object.Birthdate = Birthdate;
	object.Major = Major;
	object.Level = Level;
	object.DateEnrolled = enrolledDate;
	object.GPA = GPA;

	i++;
}

void Course::listInformation()
{
	cout << "Information for Course " << courseName;

	//output faculty
	outputFaculty();

	//output students
	outputStudents();
}

void Course::outputFaculty()
{
	//utilize operator overload to output
	cout << f;
}

void Course::outputStudents()
{
	cout << "\n\n\nThese are the Students enrolled in the " << courseName << " course:\n";

	cout << object;

	for (i = 0; i > capacity; i++) {
		cout << students.at(i);
	}
}