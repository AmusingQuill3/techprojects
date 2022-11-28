#pragma once
#include <iostream>
#include <cstdlib>
#include <cctype>
#include "Person.h"

class Faculty : public Person
{
	friend std::ostream& operator<<(std::ostream&, const Faculty&);
public:
	std::string DateHired, Title, Rank = "NULLPLACEHOLDER123";
	double Salary;

	Faculty();

	Faculty(std::string ID, std::string fName, std::string lName, std::string Birthdate, std::string Title, std::string Rank, std::string employDate, double salary);

private:

};

inline
std::ostream& operator<<(std::ostream& output, const Faculty& f)
{
	output <<
		"\nInstructor:\n" <<
		"\nFaculty ID:                   " << f.ID <<
		"\nFaculty Name:                 " << f.fName << " " << f.lName <<
		"\nBirth Date:                   " << f.Birthdate <<
		"\nDate Hired:                   " << f.DateHired <<
		"\nSalary:                       " << f.Salary;

	return output;
}