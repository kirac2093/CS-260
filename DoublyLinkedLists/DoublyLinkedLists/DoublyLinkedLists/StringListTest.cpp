// test main here

#include <iostream>
#include <string>
#include "StringList.h"

using namespace std;

int main()
{
	StringList list;

	list.insert("David");
	list.insert("Bob");
	list.insert("Alice");
	list.insert("Edward");
	list.insert("Claire");
	list.insert("Claire");
	list.printReverse();
	cout << list.find("Edward") << endl;
	cout << list.findLetterMain('B') << endl;
	//cout << list.totalItems() << endl;
	//list.remove("Alice");
	//list.remove("Claire");
	//list.printForward();

	cin.get();
	cin.ignore();
}

/*
Test each function as it’s written.  When all functions work in all cases, have main do the following in this exact order, and print the return value you get from each function call (if there was one).
Print out “Author: “, followed by your name.
Insert the following names (in the order listed): Bob, David, Alice, Edward, Claire
Print the list in order
Print the list in reverse order
Insert the following additional names: Bob, Edward, Claire, Claire
Print how many times each of the following occur: Alice, Bob, Claire, Edward
Print out how many times the letter ‘e’ occurs in the list
Remove David, Alice, and Edward
Print the list in order, and in reverse order
Remove all names (by calling removeAll).
Print the list in order and in reverse order.

*/