/*************************************************************
Name: Source.cpp
Code: Kira Corbett
Date: 5/10/18
Desc: creating, inserting, and traversing binary search trees.
	  Part2 includes destroy & copy of BST and deleting nodes.
**************************************************************/

#include <iostream>
#include "Tree.h"

using namespace std;

// function prototypes
void print(string theString, int height);

int main()
{
	// 1. create a binary search trees of strings
	Tree<string> tree1;
	Tree<string> tree2;

	cout << "CS260 A5b - Binary Trees" << endl;
	cout << "Coded by: Kira Corbett" << endl << endl;

	// 2. insert strings
	tree1.insert("Jynx");
	tree1.insert("Charmander");
	tree1.insert("Snorlax");
	tree1.insert("Clefairy");
	tree1.insert("Diglett");
	tree1.insert("Kakuna");
	tree1.insert("Meowth");
	tree1.insert("Nidorino");
	tree1.insert("Pikachu");
	tree1.insert("Blastoise");
	tree1.insert("Squirtle");
	tree1.insert("Ivysaur");
	tree1.insert("Bulbasaur");
	tree1.insert("Abra");

	// 3. print strings alphabetical order
	cout << "In Order: ";
	tree1.traverseInOrder(print);
	cout << endl << endl;

	// 4. copy tree
	tree2 = tree1;

	// 5 + 6 + 7 + 8 delete specific strings
	tree1.deleteNode("Squirtle");
	cout << "Deleting Squirtle...";
	tree1.traverseInOrder(print);
	cout << endl << endl;

	tree1.deleteNode("Meowth");
	cout << "Deleting Meowth...";
	tree1.traverseInOrder(print);
	cout << endl << endl;

	tree1.deleteNode("Blastoise");
	cout << "Deleting Blastoise...";
	tree1.traverseInOrder(print);
	cout << endl << endl;

	tree1.deleteNode("Jynx");
	cout << "Deleting Jynx...";
	tree1.traverseInOrder(print);
	cout << endl << endl;


	// 9. print copied tree inOrder, preOrder, & postOrder
	cout << "In Order: ";
	tree2.traverseInOrder(print);
	cout << endl << endl;

	cout << "Pre-Order: ";
	tree2.traversePreOrder(print);
	cout << endl << endl;

	cout << "Post-Order: ";
	tree2.traversePostOrder(print);
	cout << endl << endl;

	// 10 + 11 remove all nodes in tree
	tree2.removeTree();
	cout << "Printing copied tree...";
	tree2.traverseInOrder(print);

	cin.get();
	cin.ignore();

	return 0;
}

/*================================================================
Name: print
Desc: prints given string
Args: theString (string), height (int)
Retn: none
================================================================*/
void print(string theString, int height)
{
	cout << theString << '(' << height << ')' << " ";
}