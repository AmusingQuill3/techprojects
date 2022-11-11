#pragma once

#include <iostream>
#include <vector>
#include "Vigenere.h"

class Message
{
public:
	Vigenere v;

	std::string Key;

	Message();

	Message(std::string k);

	void setKey(std::string k);

	void encryptWord(char* token);

	void decryptWord(char* token);

	void makeFile(std::string fileName);

	void showWords();

private:
	std::vector<std::string> words;
	std::string newFileName;
};
