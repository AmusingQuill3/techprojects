#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Dealership.h"
#include "Vehicle.h"

using namespace std;

	Dealership vehicleObj;

	Dealership::Dealership()
	{

	}

	void Dealership::setDealershipInfo(Dealership InfoObj)
	{
		Name = InfoObj.Name;
		Size = InfoObj.Size * 3;
	}



	int Dealership::getDealershipSize()
	{
		return Size / 3;
	}


	bool Dealership::addVehicleTest()
	{
		//If Test is greater or equal to Size return 1 implying vector is full
		if (Test >= Size)
		{
			return 1;
		}
	return 0;
	}


	void Dealership::addVehicle()
	{
		Dealership vehicleObj;

		string Make, Model, Year;

		//Update variable
		Test = Test + 3;

		//Get make variable
		cout << "\n\nEnter vehicle make: ";

		cin >> vehicleObj.Make;

		//Add variable to vector
		vehicles.push_back(vehicleObj.Make);


		//Get model variable
		cout << "Enter vehicle model: ";

		cin >> vehicleObj.Model;

		//Add variable to vector
		vehicles.push_back(vehicleObj.Model);


		//Get year variable
		cout << "Enter vehicle year: ";
		
		cin >> vehicleObj.Year;

		//Add variable to vector
		vehicles.push_back(vehicleObj.Year);


		//Send variables to vehicle object
		//Vehicle vehicleObj(Make, Model, Year);
	}

	void Dealership::listVehicles()
	{
		//Loop to grab all variables
		for (int i = 0; i < vehicles.size(); i++)
		{
			Vehicle v;

			v.listVehiclesMake(vehicles.at(i));

			i++;

			v.listVehiclesModel(vehicles.at(i));
			

			i++;

			v.listVehiclesYear(vehicles.at(i));
	
		}
	}