#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include "Message.h"

using namespace std;


Message::Message()
{

}

Message::Message(std::string k)
{
}

void Message::setKey(std::string k)
{
	v.setKey(k);
}

void Message::encryptWord(char* token)
{
	string word = token;

	transform(word.begin(), word.end(), word.begin(), toupper);

	words.push_back(v.encrypt(word));
}

void Message::decryptWord(char* token)
{
	string word = token;

	transform(word.begin(), word.end(), word.begin(), toupper);

	words.push_back(v.decrypt(word));
}

void Message::makeFile(string fileName)
{
	newFileName = fileName;
	//Create and open ofstream with new file
	ofstream newFile(fileName);

	//Copy vector into new file
	for (int i = 0; i < words.size(); i++)
		newFile << words.at(i);

	//Close new file
	newFile.close();
}

void Message::showWords()
{
	ifstream readFile;
	string content;

	//Open file
	readFile.open(newFileName);

	//Create new array
	char Storage[1000];

	//Get content and store it in array
	while (getline(readFile, content))
	{
		//Copy and convert content to char array
		strcpy_s(Storage, content.c_str());
		//Display char array
		for (int i = 0; i < content.length(); i++)
			cout << Storage[i];
	}

	//Clear vector
	words.clear();
}