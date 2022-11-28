#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(string Name, string Genre, int Dif)
{
	name = Name;

	genre = Genre;

	difficultyLevel = Dif;

	cout << "Creating a new game\n\n";
}

void Game::outputInformation()
{
	cout << "These are the games you have played this year:\n" <<
		"Game name:           " << name <<
		"\nGame genre:          " << genre <<
		"\nDifficult Level:     " << difficultyLevel << endl << endl;
}

Game::~Game()
{
	cout << "\nIn the Game destructor\n";
}