/************************************************
Name: UnOrderedList.h
Code: Kira Corbett
Date: 4/7/18
Desc: Class definitions of UnOrderedList including
Node struct.
************************************************/
#pragma once
#include <string>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>* nextNode;
};

template <typename T>
class UnOrderedList
{
public:
	/*===========================
	Desc: default constructor
	===========================*/
	UnOrderedList()
	{
		// initializes head to NULL
		head = NULL;
	}

	/*==================================
	Desc: destructor; deletes every node
	==================================*/
	~UnOrderedList()
	{
		removeAll();
	}


	/*================================================================
	Function Name:	prepend
	Description:	inserts the given int at the beginning of
	the unordered list.
	Parameters:		userData (int)
	Return:			none
	================================================================*/
	bool prepend(T userData)
	{
		Node<T>* newNode = new Node<T>;
		Node<T>* currentNode = NULL;

		newNode = new Node<T>; // create a new node for this value
		newNode->data = userData; // store user's value in new node
		newNode->nextNode = NULL; // point to end of list (nothing)

		if (head != NULL)
		{
			if (find(userData) != 0)
			{
				return false;
			}
			else
			{
				// the new node becomes the head
				currentNode = head;
				head = newNode;
				newNode->nextNode = currentNode;
				return true;
			}
		}
		else // empty list
		{
			head = newNode;
			return true;
		}
	}

	/*================================================================
	Function Name:	append
	Description:	inserts given int at the end of unordered list
	Parameters:		userData (int)
	Return:			none
	================================================================*/
	bool append(T userData)
	{
		Node<T>* currentNode = NULL;

		// create new node and store user's data in node
		Node<T>* newNode = new Node<T>;
		newNode->data = userData;
		newNode->nextNode = NULL;

		if (head != NULL)
		{
			if (find(userData) != 0)
			{
				return false;
			}
			else
			{
				currentNode = head;

				// find the end of the list
				while (currentNode->nextNode != NULL)
				{
					currentNode = currentNode->nextNode;
				}

				currentNode->nextNode = newNode;
				return true;
			}
		}
		else // list if empty
		{
			head = newNode;
			return true;
		}
	}

	/*================================================================
	Function Name:	remove
	Description:	removes the given int from the list.
	Parameters:		userData (int)
	Return:			true if successful, false otherwise
	Adapted from:	CS-162
	================================================================*/
	bool remove(T userData)
	{

		//empty list
		if (head == NULL)
		{
			return false;
		}

		//deleting a fist item (special case because it involves modification of header)
		if (head->data == userData)
		{
			//create a temporary pointer for head (prevent memory leaks)
			Node<T>* temp = head;
			head = head->nextNode;

			//delete temporary pointer
			delete temp;
			return true;
		}

		// create previous node
		Node<T>* trail = head;
		Node<T>* nodeToDelete = head->nextNode;

		// compare current data with previous data
		while (nodeToDelete != NULL && nodeToDelete->data < userData)
		{
			trail = nodeToDelete;
			nodeToDelete = nodeToDelete->nextNode;
		}

		if (nodeToDelete != NULL)
		{
			// advance pointers and deallocate memory
			trail->nextNode = nodeToDelete->nextNode;
			delete nodeToDelete;
			return true;
		}
		return false;
	}


	/*================================================================
	Function Name:	print
	Description:	prints the list
	Parameters:		none
	Return:			none
	================================================================*/
	void print() const
	{
		Node<T>* currentNode = NULL;

		if (head == NULL)
		{
			cout << "This list is NULL." << endl;
			return;
		}

		currentNode = head;

		while (currentNode->nextNode != NULL)
		{
			cout << currentNode->data << ", ";
			currentNode = currentNode->nextNode;
		}
		cout << currentNode->data << endl;
	}


	/*================================================================
	Function Name:	count
	Description:	returns a count of the number of items in the list
	(determined by traversing each node.)
	Parameters:		none
	Return:			int
	================================================================*/
	int count() const
	{
		Node<T>* current = head;
		int count = 0;

		while (current != NULL)
		{
			// advance each node and increment counter
			current = current->nextNode;
			count++;
		}
		return count;
	}

	/*================================================================
	Function Name:	find
	Description:	returns the given int�s position in the list(e.g.
	1 if first, 2 if 2nd, etc..). Returns 0 if int is
	not in the list
	Parameters:		data (int)
	Return:			int (either given int's position or 0.)
	================================================================*/
	int find(T data) const
	{
		Node<T>* current = head;
		int intPosition = 1;

		// empty list (return 0)
		if (head == NULL)
		{
			return 0;
		}

		// if the list is not empty and the user's data does not equal the list data
		while (current->nextNode != NULL && current->data != data)
		{
			// advance to next node and increment position
			current = current->nextNode;
			intPosition++;
		}

		// if there is an item match, return the item's position
		if (current->data == data)
			return intPosition;
		else
			return 0;
	}

	/*================================================================
	Function Name:	removeAll
	Description:	removes all ints from the list
	Parameters:		none
	Return:			true if successful, false otherwise
	================================================================*/
	bool removeAll()
	{
		Node<T>* current = NULL;
		Node<T>* trail = NULL;

		current = head;

		// empty list (nothing to remove)
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
		return true;
	}

private:
	Node<T>* head;	// variable declaration for Node to track list
	int userData;	// variable for the user's input in main
};
