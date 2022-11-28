#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{

}

Student::Student(string Identification, string firstName, string lastName, string Birthday, string Major1, string Level1, string DoE, double gpa)
{
	ID = Identification;
	fName = firstName;
	lName = lastName;
	Birthdate = Birthday;
	Major = Major1;
	Level = Level1;
	DateEnrolled = DoE;
	GPA = gpa;
}