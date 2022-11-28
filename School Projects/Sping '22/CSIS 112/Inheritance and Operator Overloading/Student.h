#pragma once
#include <iostream>
#include "Person.h"

class Student : public Person
{
	friend std::ostream& operator<<(std::ostream&, const Student&);
public:
	std::string DateEnrolled, Major, Level;
	double GPA;
	int i;

	Student();

	Student(std::string ID, std::string fName, std::string lName, std::string Birthdate, std::string Major, std::string Level, std::string DoE, double GPA);

private:
};

inline
std::ostream& operator<<(std::ostream& output, const Student& s)
{
	output <<
		"\nStudent ID:                   " << s.ID <<
		"\nStudent Name:                 " << s.fName << " " << s.lName <<
		"\nBirth Date:                   " << s.Birthdate <<
		"\nDate Enrolled:                " << s.DateEnrolled <<
		"\nMajor:                        " << s.Major <<
		"\nLevel:                        " << s.Level <<
		"\nGPA:                          " << s.GPA << std::endl << std::endl;

	return output;
}