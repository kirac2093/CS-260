// class implementation

#include "StringList.h"
#include <iostream> //TEMPORARY CAN REMOVE
#include <string>

//constructor; initializes doubly linked list into empty state
StringList::StringList()
{
	head = NULL;
	tail = NULL;

	count = 0;
}

StringList::~StringList()
{
	removeAll();
}

//insert - inserts the given string in alphabetical order in the list (duplicates are allowed!)
// adapted from D.S. Malik C++ Programming
bool StringList::insert(const std::string userData)
{
	Node* currentNode = NULL; // pointer to traverse
	Node* trailNode = NULL; // 1 pointer before currentNode

	Node* newNode = new Node; // point to create node
	newNode->data = userData;
	newNode->next = NULL;
	newNode->prev = currentNode;

	//// case 1: insert into empty list
	//// case 2: insert at the beginning of nonempty list
	//// case 3: insert at the end of a nonempty list
	//// case 4: insert somewhere in a nonempty list

	//// case 1 + 2 require to change value of pointer head
	//// case 3 + 4 count incremented by 1

	//=================CASE 1==================
	// empty list
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

	//============================CASE 3======================
	// inserts newNode somewhere at the end of a nonempty list
	//========================================================
	while (currentNode != NULL && newNode->data.compare(currentNode->data) > 0)
	{
		trailNode = currentNode;
		currentNode = currentNode->next;
	}

	//============================CASE 2======================================
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
		trailNode->next = newNode;
		newNode->prev = trailNode;
		newNode->next = currentNode;
		currentNode->prev = newNode;

		count++;
		return true;
	}
	else
	{
		trailNode->next = newNode;
		newNode->prev = trailNode;

		tail = newNode;

		count++;
		return true;
	}
}

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
	//deleting the first item of the list
	//Note: Deleting the first item of the list is a special 
	//		case because it requires modification of the head
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
		//set the nextNode trail data address to the nodeToDelete address
		//then deallocate memory
		/*trailNode->next = currentNode->next;
		delete currentNode;
		count--;*/
	}

	return count;
}

int StringList::totalItems() const
{
	return count;
}

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

void StringList::printForward() const
{
	Node* currentNode = NULL;

	if (head == NULL)
	{
		std::cout << "This list is NULL." << std::endl;
		return;
	}

	currentNode = head;

	while (currentNode->next != NULL)
	{
		std::cout << currentNode->data << ", ";
		currentNode = currentNode->next;
	}
	std::cout << currentNode->data << std::endl;
}

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

/*==================================================
Desc: counts how many times the given string occurs
in the list (using recursion).
Retn: number of times given string occurs in list.
===================================================*/
int StringList::find(std::string userData)
{
	Node* currentNode = head;

	if (head == NULL)
	{
		return 0;
	}
	
	return findRecursiveHelper(head, userData);
}

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

//findLetter - counts (and returns) how many times the given letter 
//(in either upper or lower case; ie. case insensitive) occurs in the strings in the list 
//(using recursion to go through the list; you can use iteration to go through the string)
int StringList::findLetter(char userChar, Node* nodeSent)
{
	Node* currentNode = head;

	int itemsFound = 0;

	if (currentNode == NULL) // base case
	{
		return 0;
	}

	if (isupper(userChar))
	{
		tolower(userChar);
	}

	// this is the call to the helper function to count the characters in this word
	itemsFound = findLetterRecursiveHelper(0, currentNode->data, userChar);

	return (itemsFound + findLetter(userChar, currentNode->next)); // recursion
}

int StringList::findLetterRecursiveHelper(int stringTracker, std::string& searchedString, char& searchedData)
{
	int itemsFound = 0;

	for (int i = 0; i < searchedString.size(); i++)
	{
		if (searchedString[i] == searchedData)
			itemsFound++;
	}

	return itemsFound;
}

int StringList::findLetterMain(char userChar)
{
	return findLetter(userChar, head); // call the private function, passing in the head
}


