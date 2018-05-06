/*************************************************************
Name: Source.cpp
Code: Kira Corbett
Date: 5/5/18
Desc: creating, inserting, and traversing binary search trees.
**************************************************************/

#include <iostream>
#include "BinarySearchTrees.h"

using namespace std;

int main()
{
	BinarySearchTrees tree;

	cout << "CS260 Assignment 5a - Binary Trees, Part 1" << endl;
	cout << "Coded by: Kira Corbett" << endl << endl;

	tree.insert("Jynx");
	tree.insert("Charmander");
	tree.insert("Snorlax");
	tree.insert("Clefairy");
	tree.insert("Diglett");
	tree.insert("Kakuna");
	tree.insert("Meowth");
	tree.insert("Nidorino");
	tree.insert("Pikachu");
	tree.insert("Blatoise");
	tree.insert("Squirtle");
	tree.insert("Ivysaur");
	tree.insert("Bulbasaur");
	tree.insert("Abra");

	cout << "In Order: ";
	tree.printInOrder();
	cout << endl;

	cout << "Pre-Order: ";
	tree.printPreOrder(); 
	cout << endl;

	cout << "Post-Order: ";
	tree.printPostOrder();
	cout << endl;

	cin.get();
	cin.ignore();

	return 0;
}