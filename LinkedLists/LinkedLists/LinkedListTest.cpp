/************************************************
Name: LinkedListTest
Code: Kira Corbett
Date: 4/10/18
Desc: Tests LinkedLists in C++
************************************************/
#include <iostream>
#include "UnOrderedList.h"
#include "Student.h"

using namespace std;

int main() 
{

	// test template with ints --------------------------------
	UnOrderedList<int> intList;
	intList.prepend(10);
	intList.prepend(20);
	intList.prepend(5);
	intList.append(15);
	intList.append(25);
	intList.print();

	cout << endl;

	cout << "5 is in position " << intList.find(5) << endl;
	cout << "15 is in position " << intList.find(15) << endl;
	cout << "20 is in position " << intList.find(20) << endl;
	cout << "8 is in position " << intList.find(8) << endl;

	intList.remove(15);
	intList.remove(5);
	intList.remove(25);
	intList.print();

	intList.removeAll();
	intList.print();
	cout << endl << endl;

	// test on list of chars --------------------------------
	UnOrderedList<char>* charList = new UnOrderedList<char>;
	charList->append('k');
	charList->append('s');
	charList->prepend('r');
	charList->prepend('o');
	charList->prepend('w');

	charList->remove('r');
	charList->remove('w');
	charList->remove('s');
	charList->print();

	charList->removeAll();
	charList->print();
	delete charList;

	// test it on Students ------------------------------------
	Student student1("Jen", 'A');
	Student student2("Jack", 'B');
	Student student3("Jane", 'C');
	Student student4("Jelly", 'F');
	Student student5("Jackson", 'D');

	UnOrderedList<Student> studentList;

	studentList.append(student1);
	studentList.append(student1);
	studentList.append(student1);
	studentList.print();

	studentList.remove(student3);
	studentList.print();

	studentList.prepend(student3);
	studentList.prepend(student4);
	studentList.prepend(student5);
	studentList.find(student1);
	studentList.print();

	studentList.removeAll();

	studentList.print();

	cin.get();
	cin.ignore();

	return 1;
}

