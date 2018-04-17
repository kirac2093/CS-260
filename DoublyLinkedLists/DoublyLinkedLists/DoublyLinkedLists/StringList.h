// class definition

#pragma once
#include <string>
#include <string.h>

class StringList
{
private:
	struct Node
	{
		// doubly linked list
		std::string data;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;

	int count;

	int findRecursiveHelper(Node* currentNode, std::string searchedData);
	int findLetter(char userChar, Node* nodeSent);
	int findLetterRecursiveHelper(int stringTracker, std::string& searchedString, char& searchedData);

public:
	StringList();
	/*===========================
	Desc: default constructor
	===========================*/

	~StringList();
	/*===========================
	Desc: destructor
	===========================*/

	bool insert(const std::string userString);
	/*==================================================
	Desc: inserts the given string in alphabetical order
		  in the list (duplicates permitted.)
	Retn: true if successful, false otherwise
	===================================================*/

	int remove(const std::string userString);
	/*==================================================
	Desc: removes all occurrences of the given string 
		  from the list.
	Retn: returns the number of items removed (int).
	===================================================*/

	int totalItems() const;
	/*==================================================
	Desc: returns count of the number of items in list.
	Retn: returns the number of items in list (int).
	===================================================*/

	bool removeAll();
	/*==================================================
	Desc: removes all items from the list.
	Retn: true if succesful, false otherwise
	===================================================*/

	void printForward() const;
	/*==================================================
	Desc: prints the list of strings, comma delimited 
		  (all on one line), in order.
	Retn: none
	===================================================*/

	void printReverse() const;
	/*==================================================
	Desc: prints the list of strings, comma delimited
		  (all on one line) in reverse order.
	Retn: none
	===================================================*/

	int find(std::string userString);
	/*==================================================
	Desc: counts how many times the given string occurs 
		  in the list (using recursion).
	Retn: count of times given string occurs in list.
	===================================================*/

	int findLetterMain(char userChar);
	/*==================================================
	Desc: counts how many times the given letter
		  (case insensitive) occurs in strings in the list.
	Retn: count of times given letter occurs in list.
	===================================================*/
};