/************************************************
Name: UnOrderedList.cpp
Code: Kira Corbett
Date: 4/7/18
Desc: Class implmentation of UnOrderedList;
	  class functions perform various operations
	  to managing linked lists: LIST THE FUNCTIONS HERE
************************************************/
#include <iostream>
#include "UnOrderedList.h"

using namespace std;

// default constructor
UnOrderedList::UnOrderedList()
{
	// initializes head to NULL
	head = NULL;
}

UnOrderedList::~UnOrderedList()
{
	// if space was allocated, desctructor deletes nodes
	if (head != NULL)
	{
		delete head;
		head = NULL;
	}
	delete head;
	head = NULL;
}

/*================================================================
Function Name:	Prepend
Description:	Inserts the given int at the beginning of
				the unordered list.
Parameters:
Return:
================================================================*/
void UnOrderedList::Prepend(int userData)
{
	//Node* head = NULL;        // to track the list
	Node* newNode = NULL;    // for creation of new nodes

	int usersNextValue;
	char yOrN = 'n';
	bool userContinue = false;

	do {
		cout << "Please enter an integer to insert into the list: ";
		cin >> usersNextValue;

		Node* lastNode = newNode;

		newNode = new Node; // creat a new node for this value
		newNode->data = usersNextValue;
		newNode->nextNode = NULL; // node goes last, no following node

		if (head == NULL) {
			head = newNode;
		}

		if (newNode->data == userData)
		{
			cout << "Invalid action! Duplicates are not permitted." << endl;
		}
		else 
		{
			lastNode->nextNode = newNode;
		}

		// see if the user wants to insert more nodes
		cout << "Would you like to insert another node into the list? ";
		cin >> yOrN;

		if (yOrN == 'y' || yOrN == 'Y') {
			userContinue = true;
		}
		else {
			userContinue = false;
		}

	} while (userContinue);

	PrintList(head);
}


void UnOrderedList::buildListForward() {
	Node* head = NULL;        // to track the list
	Node* newNode = NULL;    // for creation of new nodes

	int usersNextValue;
	char yOrN = 'n';
	bool userContinue = false;

	do {
		cout << "Please enter an integer to insert into the list: ";
		cin >> usersNextValue;

		Node* lastNode = newNode;

		newNode = new Node; // creat a new node for this value
		newNode->data = usersNextValue;
		newNode->nextNode = NULL; // node goes last, no following node

		if (head == NULL) {
			head = newNode;
		}
		else {
			lastNode->nextNode = newNode;
		}

		// see if the user wants to insert more nodes
		cout << "Would you like to insert another node into the list? ";
		cin >> yOrN;

		if (yOrN == 'y' || yOrN == 'Y') {
			userContinue = true;
		}
		else {
			userContinue = false;
		}

	} while (userContinue);

	PrintList(head);
}

/*================================================================
Function Name:	Append
Description:	Inserts given int at the end of unordered list
Parameters:		None.
Return:			None.
================================================================*/
void UnOrderedList::Append()
{
	Node* newNode = NULL;

	int usersNextValue;
	char yOrN = 'n';
	bool userContinue = false;

	do {
		cout << "Please enter an integer to insert into the list: ";
		cin >> usersNextValue;

		newNode = new Node; // point to a newly created node
		newNode->data = usersNextValue; // places user's input in node
		newNode->nextNode = head;

		head = newNode;

		cout << "Would you like to insert another node into the list? ";
		cin >> yOrN;

		if (yOrN == 'y' || yOrN == 'Y') {
			userContinue = true;
		}
		else {
			userContinue = false;
		}

	} while (userContinue);
	PrintList(head);
}

// NOT WORKING, NEED MORE TESTING
bool UnOrderedList::Remove(int userData)
{

	//empty list
	if (head == NULL)
	{
		return false;
	}

	//deleting a fist item (special case because it involves modification of header)
	if (head->data == userData)
	{
		//create a new pointer to temporarily create a place for head to point to
		Node* temp = head;

		//points to to second node (address of 8)
		//pointing to second node removes head from pointing to the first node
		head = head->nextNode;

		//delete temporary pointer
		delete temp;
		return true;
	}

	//assuming the following
	//head -> | first node -> |second node ->| third node | fourth node| fifth node |
	//[  ]    |      [5]      |    [10]      |     [15]   |	    [20]   |    [21]    |
	//deleting an item somewhere after 1st item

	//create a previous node (called trail)
	//set trail to head since there is nothing before the first node
	Node* trail = head; //sets to 5
	Node* nodeToDelete = head->nextNode; //points to next data which is 10

									 //compares current data with next data 
									 //is nodeToDelete (10) equal to 25? No. Jump to following 
	while (nodeToDelete != NULL && nodeToDelete->data < userData)
	{
		trail = nodeToDelete;
		nodeToDelete = nodeToDelete->nextNode;
	}

	if (nodeToDelete != NULL)
	{
		trail->nextNode = nodeToDelete->nextNode;
		delete nodeToDelete;
		return true;
	}
	return false;
}



//============ CASE 1 ===========
//	If there is an empty list,
//  return false.
//===============================
//if (head = NULL)
//{
//	return false;
//	cout << "Nothing" << endl;
//}

//Node* current = head;
//Node* trail = 0;

//while (current != NULL)
//{
//	if (current->nextNode == current->data)
//	{
//		break;
//	}
//	else
//	{
//		trail = current;
//		current = current->nextNode;
//	}
//}

//// Node with "name" not found in list
//if (current == 0)
//{
//	return false;
//	cout << "Name not found." << endl;
//}
//else
//{
//	// delete from the head node
//	if (head == current)
//	{
//		head = head->nextNode;
//	}

//	// delete from somewhere after the head node
//	else
//	{
//		trail->nextNode = current->nextNode;
//	}

//	delete current;
//	//size--;
//}

////======================= CASE 2 =========================
//// Delete the first item of the list. (Note: This is a 
//// special case because it requires modification to head.
////========================================================

//if (head->data == userData)
//{
//	// create a temporary second node for the head to point to
//	// (removes head from pointing to first node)
//	Node* tempNewNode = head;
//	head = head->nextNode;

//	delete tempNewNode; // delete the temporary node
//	cout << "Deleting 1st list item: " << endl;
//	return true;
//}

////======================= CASE 3 =========================
//// Delete an item somewhere after the first item.
////========================================================
//Node* trail = head; // nothing is before the first node, so we set the last node to head.
//Node* nodeToDelete = head->nextNode; // store the data in the nextNode address.

//while (nodeToDelete != NULL)
//{
//	trail = nodeToDelete;
//	nodeToDelete = nodeToDelete->nextNode;
//}

//if (nodeToDelete != NULL && nodeToDelete->data == userData)
//{
//	// point the trail node to the nodeToDelete node to 
//	// deallocate memory
//	trail->nextNode = nodeToDelete->nextNode;
//	delete nodeToDelete;
//	return true;
//}
//return false;


void UnOrderedList::Print() const
{
	Node* current = head;

	while (current != NULL)
	{
		cout << current->data;
		if (current->nextNode != NULL)				//as long as the nextNode field is not NULL
		{
			cout << ", ";						//it prints a comma after the data
		}
		current = current->nextNode;
	}
	cout << endl;
}

/*================================================================
Function Name:	PrintList
Description:	Prints the unordered list.
Parameters:		None.
Return:			None.
================================================================*/
void UnOrderedList::PrintList(Node* theHead)
{
	Node* current = theHead;

	while (current != NULL)
	{
		// print the current integer of node
		// and then move to the next node
		cout << current->data << ' ' << endl;
		current = current->nextNode;
	}
}

/*================================================================
Function Name:	count
Description:	returns a count of the number of items in the list
				(determined by traversing each node.)
Parameters:		none
Return:			int
================================================================*/
int UnOrderedList::Count() const
{
	Node* current = head;
	int count = 0;

	while (current != NULL)
	{
		current = current->nextNode;
		count++;
	}
	return count;
}

/*================================================================
Function Name:	find
Description:	returns the given int’s position in the list(e.g.
				1 if first, 2 if 2nd, etc..). Returns 0 if int is
				not in the list
Parameters:		none
Return:			int (either given int's position or 0.)
================================================================*/
int UnOrderedList::Find(int data) const
{
	Node* current = head;
	int intPosition = 1;

	//============ CASE 1 ===========
	//	Return 0 if list is empty
	//===============================
	if (head == NULL)
	{
		return 0;
	}

	//while the list is not empty AND the user's data does not equal the list data
		//move to the next node
		//increment intPosition
	//if there is a match
		//return the numeral position
	//else return 0 (no match/not in list)

	while (current->nextNode != NULL && current->data != data)
	{
		current = current->nextNode;
		intPosition++;
	}

	if (current->nextNode != NULL && current->data == data)
		return intPosition;
	else
		return 0;
}

/*================================================================
Function Name:	removeAll
Description:	removes all ints from the list
Parameters:		data (int)
Return:			true if successful, false otherwise
================================================================*/
bool UnOrderedList::RemoveAll()
{
	Node* current = NULL;
	Node* trail = NULL;

	int count = 0;

	current = head;

	// CASE 1: empty list (nothing to remove)
	if (head = NULL)
	{
		return false;
	}

	while (current != NULL)
	{
		trail = current;	// set the last node to the current node
		current = current->nextNode;	// set the current node to the next node
		delete trail;	// deallocate memory
	}

	head = NULL;
	count = 0;
	return true;
}
