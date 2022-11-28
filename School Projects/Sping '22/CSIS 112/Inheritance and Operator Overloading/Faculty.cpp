#pragma once
#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty()
{
	Salary = 0;
}

Faculty::Faculty(string Identification, string firstName, string lastName, string Birthday, string Title1, string Rank1, string employDate, double salary)
{
	ID = Identification;
	fName = firstName;
	lName = lastName;
	Birthdate = Birthday;
	Title = Title1;
	Rank = Rank1;
	Salary = salary;
	DateHired = employDate;
}
