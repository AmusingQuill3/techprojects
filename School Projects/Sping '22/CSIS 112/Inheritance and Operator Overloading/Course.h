#pragma once

#include <iostream>
#include <vector>
#include "Faculty.h"
#include "Student.h"

class Course
{
public:
	Course();

	void setcourseInfo(std::string name, int maxcap); //Set course info

	void addFaculty();

	void addStudent();

	void listInformation();

	void outputFaculty();
	
	void outputStudents();

private:
	//Create Variables
	std::string courseName;
	int capacity, i = 1;
	bool test;

	//Create Faculty Object
	Faculty f;
	
	//Create student object
	Student object;

	//Create Students Vector
	std::vector<Student> students;

	std::vector<Student>::iterator it;
};