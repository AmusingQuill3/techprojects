#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Vigenere.h"

using namespace std;

Vigenere::Vigenere()
{

}

void Vigenere::setKey(string k)
{
	key = toUpperCase(k);
}

string Vigenere::getKey()
{
	return key;
}

string Vigenere::toUpperCase(string k)
{
	transform(k.begin(), k.end(), k.begin(), toupper);
		

	return k;
}

string Vigenere::encrypt(string word)
{
	string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c + key[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
		j = (j + 1) % key.length();
	}
	return output;
}

string Vigenere::decrypt(string word)
{
	string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c - key[j] + 26) % 26 + 'A';//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
		j = (j + 1) % key.length();
	}
	return output;

}