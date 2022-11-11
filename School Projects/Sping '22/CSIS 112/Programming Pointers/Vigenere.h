#pragma once

#include <iostream>

class Vigenere
{
public:

	Vigenere();

	void setKey(std::string k);

	std::string getKey();

	std::string toUpperCase(std::string k);

	std::string encrypt(std::string word);

	std::string decrypt(std::string word);

private:
	std::string key;
	char upperCase[1000];
};