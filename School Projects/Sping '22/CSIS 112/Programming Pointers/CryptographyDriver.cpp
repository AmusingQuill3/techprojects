//CSIS 112 Class Composition -- 
//CSIS 112-B02

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Message.h"
#include "Vigenere.h"

using namespace std;

int displayMenu();

int main()
{
	//Introduction
	cout << "Elijah Bixby -- Programming Pointers Assignment\n\n";

	//Create variables
	int Selection = 0, aPlaceholder = 0;
	string Key, fileName, fileName2, content;

	char* token1 = NULL;
	char* token2 = NULL;
	char* next_token1 = NULL;
	char* next_token2 = NULL;
	char seps[] = " ,\t\n";

	char Storage[1000];

	//Create fstream
	ifstream File;

	//Call on Message Class
	Message m;
	Vigenere v;

	//Get Encryption Key
	cout << "Enter an encryption / decryption key :  ";
	cin >> Key;

	m.setKey(Key);

	//Create Message Object
	Message MessageObj (Key);

	//Call on Message function to add Key
	MessageObj.Key = Key;
	Message(MessageObj.Key);

	//Loop until user ends
	do
	{
		//Call on function to display menu
		Selection = displayMenu();

		//Utilize switch for menu selection
		switch (Selection) {

		case 1:
			cout << "\nEnter the name of the file to encrypt:   ";

			//Get file name
			cin.ignore();
			getline(cin, fileName);
			
			//Open file
			File.open(fileName);

			//Get content and store it in array
			while (getline(File, content))
			{
				//Copy and convert content to char array
				strcpy_s(Storage, content.c_str());
				//Display char array
				for (int i = 0; i < content.length(); i++)
					cout << Storage[i];
			}

			//Close file
			File.close();

			//Create token
			token1 = strtok_s(Storage, seps, &next_token1);

			//Encrypting
			while (token1 != NULL)
			{
				//Call on encryption
				m.encryptWord(token1);
				token1 = strtok_s(NULL, seps, &next_token1);
			}

			//Give instructions
			cout << "A new file will be created that contains the encrypted message.\n\n" <<
				"Please enter the name of the new file to create:   ";

			//Get file name
			cin.ignore();
			getline(cin, fileName2);

			//Create new file
			m.makeFile(fileName2);

			//Get instructions
			cout << "The new file contains the following encrypted message.\n\n";

			//Output new file
			m.showWords();
			break;

		case 2:
			cout << "\nEnter the name of the file to decrypt:   ";


			//Get file name
			cin.ignore();
			getline(cin, fileName);

			//Open file
			File.open(fileName);

			//Get content and store it in array
			while (getline(File, content))
			{
				//Copy and convert content to char array
				strcpy_s(Storage, content.c_str());
				//Display char array
				for (int i = 0; i < content.length(); i++)
					cout << Storage[i];
			}

			File.close();

			//Create token
			token2 = strtok_s(Storage, seps, &next_token2);

			//Encrypting
			while (token2 != NULL)
			{
				//Call on encryption
				m.decryptWord(token2);
				token2 = strtok_s(NULL, seps, &next_token2);
			}

			//Give instructions
			cout << "\nA new file will be created that contains the encrypted message.\n\n" <<
				"Please enter the name of the new file to create:   ";

			//Get file name
			cin.ignore();
			getline(cin, fileName2);

			//Create new file
			m.makeFile(fileName2);

			//Get instructions
			cout << "The new file contains the following decrypted message.\n\n";

			//Output new file
			m.showWords();

			break;

		case 3:
			system("pause");
			break;

		default:
			cout << "Error";
		}
	} while (Selection != 3);

	return 0;
}

//Print menu function
int displayMenu()
{
	//Create variables
	int Selection;

	//Create menu
	cout << "\n\n    Vigenere Cyper\n\n";
	cout << "      Main Menu\n\n";
	cout << "    1 - Encrypt File\n";
	cout << "    2 - Decrypt File\n";
	cout << "    3 - Quit\n\n\n";
	cout << "    Selection: ";

	//Grab input
	cin >> Selection;

	//Return input to be used by main()
	return Selection;
}