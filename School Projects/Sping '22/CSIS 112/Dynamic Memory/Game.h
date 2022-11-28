#pragma once
#include <iostream>

class Game
{
public:
	Game(std::string Name, std::string Genre, int Dif);

	void outputInformation();

	~Game();

private:
	std::string name, genre;
	int difficultyLevel;
};
