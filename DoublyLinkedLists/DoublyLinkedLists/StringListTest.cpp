/**************************************************
Name: StringListTest.cpp
Code: Kira Corbett
Date: 4/17/18
Desc: Practice with implementing and using doubly 
	  linked lists and recursion through traversal.
***************************************************/

#include <iostream>
#include <string>
#include "StringList.h"

using namespace std;

int main()
{
	StringList list;

	cout << "Author: " << "Kira Corbett" << endl << endl;

	list.insert("Bob");
	list.insert("David");
	list.insert("Alice");
	list.insert("Edward");
	list.insert("Claire");

	cout << "Print Forward: ";
	list.printForward();
	cout << "Print Reversed: ";
	list.printReverse();

	cout << endl;
	cout << "==================================================================================" << endl;
	cout << endl;

	list.insert("Bob");
	list.insert("Edward");
	list.insert("Claire");
	list.insert("Claire");
	cout << "Updated List: ";
	list.printForward();

	cout << "Alice occurs " << list.find("Alice") << " time(s) in the list." << endl;
	cout << "Bob occurs " << list.find("Bob") << " time(s) in the list." << endl;
	cout << "Claire occurs " << list.find("Claire") << " time(s) in the list." << endl;
	cout << "Edward occurs " << list.find("Edward") << " time(s) in the list." << endl;
	cout << "The letter 'e' occurs " << list.findLetter('e') << " time(s) in the list." << endl;

	cout << "==================================================================================" << endl;
	cout << endl;

	cout << "Remove David, Alice, and Edward from the list." << endl;
	cout << list.remove("David");
	cout << list.remove("Alice");
	cout << list.remove("Edward");

	cout << "Print Forward: ";
	list.printForward();
	cout << "Print Reversed: ";
	list.printReverse();

	cout << endl;
	cout << "==================================================================================" << endl << endl;
	cout << "Removing all data..." << endl;
	list.removeAll();
	list.printForward();
	list.printReverse();
	cout << "==================================================================================" << endl << endl;

	cin.get();
	cin.ignore();
}