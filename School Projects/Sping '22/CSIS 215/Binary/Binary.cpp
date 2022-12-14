#include <iostream>
#include "BST.h"
#include "BSTNode.h"
#include "book.h"
#include "BinNode.h"

using namespace std;

int main(int argc, char** argv)
{
	BST<int, string> testTree;

	cout << "Double Threaded Binary Tree Assignment" << endl;
	cout << "---------------------------------------" << endl;

	testTree.insert(77, "seventy-seven"); //inserting KV pairs
	testTree.insert(70, "seventy");
	testTree.insert(75, "seventy-five");
	testTree.insert(66, "sixty-six");
	testTree.insert(79, "seventy-nine");
	testTree.insert(68, "sixty-eight");
	testTree.insert(67, "sixty-seven");
	testTree.insert(69, "sixty-nine");
	testTree.insert(90, "ninety");
	testTree.insert(85, "eighty-five");
	testTree.insert(83, "eighty-three");
	testTree.insert(87, "eighty-seven");
	testTree.insert(65, "sixty-five");

	cout << "The size of this BST tree is: " << testTree.size() << endl;
	cout << "The tree's structure is: " << endl << endl;

	testTree.print(); // printing stree structure

	cout << "----------------------------------------------" << endl;
	cout << "Inorder printing of the tree: " << endl << endl;

	testTree.printInorder(); //printing -- inorder traversal

	cout << "--------------------------------------------" << endl;
	cout << "Reverse order printing of the tree: " << endl << endl;

	testTree.printReverse();

	return 0;

}
