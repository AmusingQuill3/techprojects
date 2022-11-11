#pragma once
#include <string>
#include <vector>

class Student
{
public:

	void getStudentName(std::string StudentX);


	void getCourseName(std::string ClassY);


	void AddGrade(int GradeZ);


	void sortVector();


	double findMean();


	int findMax();


	int findMin();


	int getNumGrades();


	void disInformation();


private:
	//Create variables
		//Students and Course Name
	std::string StudentName, CourseName;

	//Vector
	std::vector<int> grades;
};