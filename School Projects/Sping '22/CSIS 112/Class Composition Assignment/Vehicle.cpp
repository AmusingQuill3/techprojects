#include <iostream>
#include <string>
#include "Dealership.h"
#include "Vehicle.h"

using namespace std;


	void Vehicle::listVehiclesMake(string Make)
	{
		cout << "Make:  " << Make;
	}

	void Vehicle::listVehiclesModel(string Model)
	{
		cout << "\nModel:  " << Model;
	}

	void Vehicle::listVehiclesYear(string Year)
	{
		cout << "\nYear:  " << Year << endl << endl << endl;
	}