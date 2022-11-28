//CSIS 112 Dynamic Memory -- Use pointers and dynamic arrays and objects
//CSIS 112-B02
//Sources: https://stackoverflow.com/questions/20303820/creation-of-dynamic-array-of-dynamic-objects-in-c

#include <iostream>
#include <string>
#include <random>
#include "Game.h"

using namespace std;

int main()
{
	//Introduction
	cout << "Elijah Bixby -- Class Composition\n\n";

	//Create variables
	int* ptr = new int;

	int size, x, y, z;
	string name, genre;

	//Get amount of games
	cout << "How many games have you played in the last year?\n";

	//Get array size
	cin >> size;

	//Create Object
	Game** Object;
	Object = (Game**)malloc(size * sizeof(Game*));

	//For loop to get game information
	for (y = size; y > 0; y--)
	{
		//Get Name of the game
		cout << "What is the name of a game?\n";

		cin.ignore();
		getline(cin, name);

		//Get genre of the game
		cout << "What is the genre of the " << name << " game?\n";
		
		cin.ignore();
		getline(cin, genre);

		//Retrieve random number
		z = 1 + rand() % (11 - 1);	

		//Create array
		int i = 0;
		Object[i] = new Game(name, genre, z);
		i++;
	}

	for (x = 0; x < size; x++)
	{
		//Output array
		Object[x]->outputInformation();
	}


	for (x = 0; x < size; x++)
	{
		delete Object[x];
	}

	return 0;
}