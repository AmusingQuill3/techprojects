// main.cpp
#include <iostream>
#include <string>
#include <fstream>
#include "CountSelfOrderedList.h"
#include "MTFSelfOrderedList.h"
#include "TransposeSelfOrderedList.h"

using namespace std;

int main()
{

	cout << "------------------------------------------" << endl << endl;

	cout << "\t\tTEST 1" << endl;
	cout << "------------------------------------------" << endl << endl;

	CountSelfOrderedList<char> c;
	c.add('A');
	c.add('B');
	c.add('C');
	c.add('D');
	c.add('E');
	c.add('F');
	c.add('G');
	c.add('H');


	c.find('F');
	c.find('D');
	c.find('F');
	c.find('G');
	c.find('E');
	c.find('G');
	c.find('F');
	c.find('A');
	c.find('D');
	c.find('F');
	c.find('G');
	c.find('E');
	c.find('H');
	c.find('I');

	cout << "CountSelfOrderedList compares: " << c.getCompares() << endl;
	c.printlist();


	MTFSelfOrderedList<char> mtf;
	mtf.add('A');
	mtf.add('B');
	mtf.add('C');
	mtf.add('D');
	mtf.add('E');
	mtf.add('F');
	mtf.add('G');
	mtf.add('H');


	mtf.find('F');
	mtf.find('D');
	mtf.find('F');
	mtf.find('G');
	mtf.find('E');
	mtf.find('G');
	mtf.find('F');
	mtf.find('A');
	mtf.find('D');
	mtf.find('F');
	mtf.find('G');
	mtf.find('E');
	mtf.find('H');
	mtf.find('I');

	cout << "\nMove-to-front compares: " << mtf.getCompares() << endl;
	mtf.printlist();


	TransposeSelfOrderedList<char> t;
	t.add('A');
	t.add('B');
	t.add('C');
	t.add('D');
	t.add('E');
	t.add('F');
	t.add('G');
	t.add('H');


	t.find('F');
	t.find('D');
	t.find('F');
	t.find('G');
	t.find('E');
	t.find('G');
	t.find('F');
	t.find('A');
	t.find('D');
	t.find('F');
	t.find('G');
	t.find('E');
	t.find('H');
	t.find('I');

	cout << "\n\nTransposeSelfOrderedList compares: " << t.getCompares() << endl;
	t.printlist();


	cout << "\n\n------------------------------------------" << endl << endl;

	cout << "\t\tTEST 2" << endl;
	cout << "------------------------------------------" << endl << endl;

	// open file
	fstream input;
	input.open("test.txt");

	CountSelfOrderedList<string> cs;
	MTFSelfOrderedList<string> mtfs;
	TransposeSelfOrderedList<string> ts;

	string word;

	// gets file and places into lists
	while (input >> word)
	{
		cs.add(word);
		mtfs.add(word);
		ts.add(word);
	}

	// count print
	cout << "CountSelfOrderedList Heuristic" << endl;
	cout << "Size: " << cs.size() << endl;
	cout << "Compares: " << cs.getCompares() << endl << endl;
	cs.printlist(10);

	// move-to-front print
	cout << "\nMove-To-Front Heuristic" << endl;
	cout << "Size: " << mtfs.size() << endl;
	cout << "Compares: " << mtfs.getCompares() << endl << endl;
	mtfs.printlist(10);

	// transpose print
	cout << "\nTransposeSelfOrderedList Heuristic" << endl;
	cout << "Size: " << ts.size() << endl;
	cout << "Compares: " << ts.getCompares() << endl << endl;
	ts.printlist(10);

	input.close();
	system("pause");

	return 0;
}