/*************************************************************
Name: BinarySearchTrees.cpp
Code: Kira Corbett
Date: 5/5/18
Desc: class implementation for binary search trees.
**************************************************************/
#include <iostream>
#include "BinarySearchTrees.h"

// function prototypes
void print(string theString);

BinarySearchTrees::BinarySearchTrees()
{
	root = NULL;
}

BinarySearchTrees::~BinarySearchTrees()
{

}

/*================================================================
Name: insert
Desc: inserts user's string(s) into the binary search tree
Args: data (string)
Retn: true if successful, false otherwise
Note: Adapted from C++ Programming by D.S. Malik
================================================================*/
bool BinarySearchTrees::insert(string data)
{
	// initialize variables and allocate memory for new nodes
	treeNode* currentNode = NULL; // pointer to traverse
	treeNode* trailCurrent = NULL; // pointer to follow current

	treeNode* newTreeNode = new treeNode; // pointer to create node
	newTreeNode->data = data;
	newTreeNode->left = NULL;
	newTreeNode->right = NULL;

	// checks for empty tree
	if (root == NULL)
	{
		root = newTreeNode;
		return true;
	}

	if (root != NULL)
	{
		currentNode = root;

		while (currentNode != NULL)
		{
			trailCurrent = currentNode;

			// sort strings to the left and right of tree
			if (currentNode->data.compare(data) > 0)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->right;
			}
		}

		// keep track of previous items
		if (trailCurrent->data.compare(data) > 0)
		{
			trailCurrent->left = newTreeNode;
		}
		else
		{
			trailCurrent->right = newTreeNode;
		}
		return true;
	}

	// TODO: implement ALL routines recursive for BST
	//=========================Recursive traversal of Binary Search Tree======================
	//if (current == NULL)
	//{
	//	current = new treeNode;
	//	current->data = data;
	//	current->left = NULL;
	//	current->right = NULL;
	//	return true;
	//}
	//else // general case
	//{
	//	if (data < current->data)
	//	{
	//		return insert(current->left, data);
	//	}
	//	else
	//	{
	//		return insert(current->right, data);
	//	}
	//}
	//==========================================================================================
}

/*================================================================
Name: printInOrder
Desc: prints tree: left, root, right
Args: none
Retn: none
================================================================*/
void BinarySearchTrees::printInOrder()
{
	printInOrderR(root, print);
}

/*================================================================
Name: printPreOrder
Desc: prints tree: root, left, right (used for deletion).
Args: none
Retn: none
================================================================*/
void BinarySearchTrees::printPreOrder()
{
	printPreOrderR(root, print);
}

/*================================================================
Name: printPostOrder
Desc: prints tree: left, right, root (used for copy)
Args: none
Retn: none
================================================================*/
void BinarySearchTrees::printPostOrder()
{
	printPostOrderR(root, print);
}

/*================================================================
Name: printInOrderR
Desc: recursive call to print in order
Args: current (treeNode pointer)
Retn: none
Note: adapted from C++ Programming by D.S. Malik
================================================================*/
void BinarySearchTrees::printInOrderR(treeNode* current, const function<void(string)> &funcToCall)
{
	if (current != NULL)
	{
		printInOrderR(current->left, funcToCall);
		funcToCall(current->data);
		printInOrderR(current->right, funcToCall);
	}
}

/*================================================================
Name: printPreOrderR
Desc: recursive call to print pre-order
Args: current (treeNode pointer)
Retn: none
Note: adapted from C++ Programming by D.S. Malik
================================================================*/
void BinarySearchTrees::printPreOrderR(treeNode* current, const function<void(string)> &funcToCall)
{
	if (current != NULL)
	{
		funcToCall(current->data);
		printPreOrderR(current->left, funcToCall);
		printPreOrderR(current->right, funcToCall);
	}
}

/*================================================================
Name: printPostOrderR
Desc: recursive call to print post-order
Args: current (treeNode pointer)
Retn: none
Note: adapted from C++ Programming by D.S. Malik
================================================================*/
void BinarySearchTrees::printPostOrderR(treeNode* current, const function<void(string)> &funcToCall)
{
	if (current != NULL)
	{
		printPostOrderR(current->left, funcToCall);
		printPostOrderR(current->right, funcToCall);
		funcToCall(current->data);
	}
}

/*================================================================
Name: print
Desc: prints given string
Args: theString (string)
Retn: none
================================================================*/
void print(string theString)
{
	cout << theString << " ";
}