#pragma once
#include <string>
#include <vector>


class Dealership
{
public:

	std::string Name, Make, Model, Year;
	int Size;


	Dealership();


	friend class Vehicle;


	void setDealershipInfo(Dealership InfoObj);


	int getDealershipSize();


	bool addVehicleTest();


	void addVehicle();


	void listVehicles();

private:
	//Create placeholder variables
	int Test = 0;

	//Create vector
	std::vector<std::string> vehicles;

};