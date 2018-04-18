/**************************************************
Name: StringList.cpp
Code: Kira Corbett
Date: 4/17/18
Desc: Class implementation for String class
***************************************************/

#include "StringList.h"
#include <iostream>
#include <string>

/*===========================
Desc: default constructor
===========================*/
StringList::StringList()
{
	head = NULL;
	tail = NULL;

	count = 0;
}

/*===========================
Desc: destructor
===========================*/
StringList::~StringList()
{
	removeAll();
}

/*================================================================
Name: insert
Desc: inserts the given string in alphabetical order in the list 
	  (duplicates permitted.)
Args: userData (string) const
Retn: true if successful, false otherwise
Adaptions with tail nodes: D.S. Malik C++ Programming
================================================================*/
bool StringList::insert(const std::string userData)
{
	Node* currentNode = NULL; // pointer to traverse
	Node* trailNode = NULL; // 1 pointer before currentNode

	Node* newNode = new Node; // point to create node
	newNode->data = userData;
	newNode->next = NULL;
	newNode->prev = currentNode;

	// case 1: insert into empty list
	// case 2: insert somewhere in a nonempty list
	// case 3: insert at the beginning of nonempty list
	// case 4: insert at the end of a nonempty list

	//=================CASE 1==================
	// insert into empty list
	//=========================================
	if (head == NULL)
	{
		// newNode is only node
		head = newNode;
		tail = newNode;

		count++;
		return true;
	}

	currentNode = head;

	//============================CASE 2======================
	// inserts newNode somewhere at the end of a nonempty list
	//========================================================
	while (currentNode != NULL && newNode->data.compare(currentNode->data) > 0)
	{
		trailNode = currentNode;
		currentNode = currentNode->next;
	}

	//============================CASE 3======================================
	// insert newNode at the beginning of nonempty list
	// checks if the item is less than the first item (smallest item of list)
	//========================================================================
	if (newNode->data.compare(head->data) < 0)
	{
		// if item is the smallest, new item becomes the beginning of list
		head->prev = newNode;
		newNode->next = head;

		head = newNode;

		count++;
		return true;
	}
	else if (currentNode != NULL)
	{
		// insert somewhere in the list 
		trailNode->next = newNode;
		newNode->prev = trailNode;
		newNode->next = currentNode;
		currentNode->prev = newNode;

		count++;
		return true;
	}
	else
	{
		// case 4: insert at the end of a nonempty list
		trailNode->next = newNode;
		newNode->prev = trailNode;

		tail = newNode;

		count++;
		return true;
	}
}

/*================================================================
Name: remove
Desc: removes all occurrences of the given string from the list.
Args: nodeToDelete (string) const
Retn: returns the number of items removed (int).
================================================================*/
int StringList::remove(const std::string nodeToDelete)
{
	// case 1: the list is empty
	// case 2: the item to be deleted is in the first node of list (requires modification of head)
	// case 3: item to be deleted is somewhere in the list
	// case 4: item to be delete is not in the list

	Node* currentNode = NULL; // pointer to traverse list
	Node* trailNode = NULL; // 1 pointer before currentNode

	Node* newNode = new Node;

	//============ CASE 1 ===========
	//if there is an empty list
	//===============================
	if (head == NULL)
	{
		std::cout << "Error! Cannot delete an empty list." << std::endl;
	}

	//======================= CASE 2 =========================
	// deleting the first item of the list (requires 
	// modification of head)
	//========================================================
	if (head->data == nodeToDelete)
	{
		currentNode = head;
		head = head->next;

		if (head != NULL)
			head->prev = NULL;
		else
			tail = NULL;

		count--;

		delete currentNode;
	}

	/*==================== CASE 3 =================
	deleting an item somewhere after the 1st item
	=============================================*/
	trailNode = head;	//set trail to head since there is nothing before first node
	currentNode = head->next;	//stores data in next node address

	//compare current data with nextNode data
	while (currentNode != NULL && currentNode->data.compare(nodeToDelete) < 0)
	{
		trailNode = currentNode;
		currentNode = currentNode->next;
	}

	if (currentNode != NULL && currentNode->data == nodeToDelete)
	{
		trailNode = currentNode->prev;
		trailNode->next = currentNode->next;

		currentNode->next->prev = trailNode;

		if (currentNode == tail)
		{
			tail = trailNode;
		}

		count--;
		delete currentNode;
	}

	return count;
}

/*================================================================
Name: totalItems
Desc: returns count of the number of items in list.
Args: none
Retn: returns the number of items in list (int).
================================================================*/
int StringList::totalItems() const
{
	return count;
}
	
/*================================================================
Name: removeAll
Desc: removes all items from the list.
Args: none
Retn : true if succesful, false otherwise
Adaptions: Doubly Linked Lists D.S. Malik in C++ Programming
================================================================*/
// adapted from Doubly Linked Lists D.S. Malik
bool StringList::removeAll()
{
	Node* temp;

	// empty list (nothing to remove)
	if (head = NULL)
	{
		return false;
	}

	while (head != NULL)
	{
		temp = head; // move nodes to temporary spot
		head = head->next; // advance nodes
		delete temp; // deallocate memory
	}

	tail = NULL;

	count = 0;

	return false;
}

/*================================================================
Name: printForward
Desc: prints the list of strings, comma delimited (all on one line)
	  in order.
Args: none
Retn: none
================================================================*/
void StringList::printForward() const
{
	Node* currentNode = NULL;

	if (head == NULL)
	{
		// empty list
		std::cout << "This list is NULL." << std::endl;
		return;
	}

	currentNode = head;

	while (currentNode->next != NULL)
	{
		// if the next node is not NULL, print a comma
		std::cout << currentNode->data << ", ";
		currentNode = currentNode->next;
	}
	std::cout << currentNode->data << std::endl;
}

/*================================================================
Name: printReverse
Desc: prints the list of strings, comma delimited (all on one line) 
	  in reverse order.
Args: none
Retn: none
================================================================*/
void StringList::printReverse() const
{
	Node* currentNode = NULL;

	if (head == NULL)
	{
		std::cout << "This list is NULL." << std::endl;
		return;
	}

	currentNode = tail;

	while (currentNode != NULL)
	{
		std::cout << currentNode->data << ", ";
		currentNode = currentNode->prev;
	}
}

/*================================================================
Name: find
Desc: counts how many times the given string occurs in the list 
	  (using recursion).
Args: userData (string)
Retn: number of times given string occurs in list (int).
================================================================*/
int StringList::find(std::string userData)
{
	Node* currentNode = head;

	if (head == NULL)
	{
		return 0;
	}

	return findRecursiveHelper(head, userData);
}

/*================================================================
Name: findRecursiveHelper
Desc: helper function to assist find() function by accessing Node*
Args: currentNode (Node*), searchedData (string)
Retn: number of strings found
================================================================*/
int StringList::findRecursiveHelper(Node* currentNode, std::string searchedData)
{
	int itemsFound = 0;

	if (currentNode == NULL)
		return 0;

	if (currentNode->data == searchedData)
		itemsFound++;

	itemsFound += findRecursiveHelper(currentNode->next, searchedData);

	return itemsFound;
}

/*================================================================
Name: findLetter
Desc: counts how many times the given letter (case insensitive) 
	  occurs in strings in list.
Args: userChar (char), nodeSent (Node*)
Retn: count of times given letter occurs in list.
================================================================*/
int StringList::findLetter(char userChar, Node* nodeSent)
{
	Node* currentNode = nodeSent;

	int itemsFound = 0;

	if (currentNode == NULL) // base case
	{
		return 0;
	}

	// calls the helper function to count the chars in this string
	itemsFound = findLetterRecursiveHelper(currentNode->data, userChar);

	// recursively return the count of times the given letter occurs in list.
	return (itemsFound + findLetter(userChar, currentNode->next));
}

/*================================================================
Name: findLetterRecursiveHelper
Desc: helper function to iterate through chars in findLetter()
Args: searchedString (string) , searchedData (char)
Retn: number of chars found
================================================================*/
int StringList::findLetterRecursiveHelper(std::string searchedString, char searchedData)
{
	int itemsFound = 0;

	// iteratively traverse through the strings
	for (int i = 0; i < searchedString.length(); i++)
	{
		// if the string is upper case or lower case
		if (searchedString[i] == toupper(searchedData) || searchedString[i] == tolower(searchedData))
		{
			// contributes to the overall number of chars
			itemsFound++;
		}
	}

	return itemsFound;
}

/*================================================================
Name: findLetter
Desc: helper function for findLetter() recursion
Args: userChar (char)
Retn: findLetter()
================================================================*/
int StringList::findLetter(char userChar)
{
	// call the private function to pass in head
	return findLetter(userChar, head); 
}