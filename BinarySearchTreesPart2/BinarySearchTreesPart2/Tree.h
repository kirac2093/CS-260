/*************************************************************
Name: Tree.h
Code: Kira Corbett
Date: 5/10/18
Desc: header file for binary tree structures
**************************************************************/

#pragma once

#include <string>
#include <functional>
#include <algorithm>

using namespace std;

template <class T>
struct nodeType
{
	T data;
	nodeType<T>* left;
	nodeType<T>* right;
};

template <class T>
class Tree
{
public:
	const Tree<T>& operator=(const Tree<T>&);
	// operator overload (assignment operator)

	Tree(const Tree<T>& anotherTree);
	/*===========================
	Desc: copy tree constructor
	===========================*/

	Tree();
	/*==================
	Desc: constructor
	==================*/

	~Tree();
	/*====================
	Desc: destructor
	====================*/

	void traverseInOrder(const function<void(string, int)> &funcToCall);
	/*========================================================
	Desc: recursive call to print in order
	Retn: none
	========================================================*/

	void traversePreOrder(const function<void(string, int)> &funcToCall);
	/*========================================================
	Desc: root, left, right (used for deletion)
	Retn: none
	========================================================*/

	void traversePostOrder(const function<void(string, int)> &funcToCall);
	/*========================================================
	Desc: left, right, root (used for copy)
	Retn: none
	========================================================*/

	bool insert(T userData);
	/*========================================================
	Desc: inserts user's string(s) into the binary search tree
	Retn: true if successful, false otherwise
	========================================================*/

	void deleteNode(const T& itemToDelete);
	/*========================================================
	Desc: deletes user-entered node
	Retn: none
	========================================================*/

	void removeTree();
	/*========================================================
	Desc: destroys entire binary search tree
	Retn: none
	========================================================*/

private:
	nodeType<T>* root;

	bool found;

	// recursive calls for traversal routines (private because they handle tree nodes)
	void traverseInOrderR(nodeType<T>* current, const function<void(string, int)> &funcToCall, int height);

	void traversePreOrderR(nodeType<T>* current, const function<void(string, int)> &funcToCall);

	void traversePostOrderR(nodeType<T>* current, const function<void(string, int)> &funcToCall);

	void deepCopy(nodeType<T>* &copiedTreeRoot, nodeType<T>* ourTreeRoot);
	/*========================================================
	Desc: creates a deepy copy of tree
	Note: copied tree is NOT related to original tree
	Retn: none
	========================================================*/

	nodeType<T>* search(nodeType<T>* currentNode, const T& itemToDelete);
	/*==================================================================
	Desc: searches for the node to delete
	Retn: nodeToDelete
	==================================================================*/

	void deleteFromTree(nodeType<T>* &nodePointer);
	/*========================================================
	Desc: deletes user-entered node from tree
	Retn: none
	========================================================*/

	int nodeHeight(nodeType<T> *nodePointer) const;
	/*========================================================
	Desc: calculates the height of a node in the tree
	Retn: height (int)
	========================================================*/

	bool removeAllNodes(nodeType<T>* &nodeToDelete);
	/*========================================================
	Desc: deallocates memory & deletes all nodes from tree
	Retn: none
	========================================================*/
};

// constructor
template <class T>
Tree<T>::Tree()
{
	root = NULL;
}

// copy constructor
template <class T>
Tree<T>::Tree(const Tree<T>& otherTree)
{
	if (otherTree.root == NULL)
		root == NULL;
	else
		deepCopy(root, otherTree.root);
}

// destructor
template <class T>
Tree<T>::~Tree()
{
	removeAllNodes(root);
}

// operator overload
// adapted from C++ Programming from D.S. Malik
template <class T>
const Tree<T>& Tree<T>::operator=(const Tree<T>& otherTree)
{
	// if there is not already a copied tree
	if (this != &otherTree)
	{
		if (root != NULL) // not empty tree
		{
			removeAllNodes(root);
		}
		if (otherTree.root == NULL) // copied tree not empty
		{
			root = NULL;
		}
		else // then we can copy
		{
			deepCopy(root, otherTree.root);
		}
	}

	return *this;
}

/*================================================================
Name: printInOrder
Desc: prints tree: left, root, right
Args: funcToCall (function pointer: string, int)
Retn: none, funcToCall (none)
================================================================*/
template <class T>
void Tree<T>::traverseInOrder(const function<void(string, int)> &funcToCall)
{
	traverseInOrderR(root, print, 0);
}

/*================================================================
Name: printPreOrder
Desc: prints tree: root, left, right (used for deletion).
Args: funcToCall (function pointer: string, int)
Retn: none, funcToCall (none)
================================================================*/
template <class T>
void Tree<T>::traversePreOrder(const function<void(string, int)> &funcToCall)
{
	traversePreOrderR(root, print);
}

/*================================================================
Name: printPostOrder
Desc: prints tree: left, right, root (used for copy)
Args: funcToCall (function pointer: string, int)
Retn: none, funcToCall (none)
================================================================*/
template <class T>
void Tree<T>::traversePostOrder(const function<void(string, int)> &funcToCall)
{
	traversePostOrderR(root, print);
}

/*====================================================================
Name: printInOrderR
Desc: recursive call to print in order
Args: current (treeNode), funcToCall (function pointer), height (int)
Retn: none
Note: adapted from C++ Programming by D.S. Malik
====================================================================*/
template <class T>
void Tree<T>::traverseInOrderR(nodeType<T>* current, const function<void(string, int)> &funcToCall, int height)
{
	if (current != NULL)
	{
		// increment height if item entered to the left or right of tree
		traverseInOrderR(current->left, funcToCall, ++height);
		funcToCall(current->data, --height);
		traverseInOrderR(current->right, funcToCall, ++height);
	}
}

/*================================================================
Name: printPreOrderR
Desc: recursive call to print pre-order
Args: current (treeNode), funcToCall (function pointer)
Retn: none
Note: adapted from C++ Programming by D.S. Malik
================================================================*/
template <class T>
void Tree<T>::traversePreOrderR(nodeType<T>* current, const function<void(string, int)> &funcToCall)
{
	int height = 0;

	if (current != NULL)
	{
		height = nodeHeight(current);
		funcToCall(current->data, height);
		traversePreOrderR(current->left, funcToCall);
		traversePreOrderR(current->right, funcToCall);
	}
}

/*================================================================
Name: printPostOrderR
Desc: recursive call to print post-order
Args: current (treeNode), funcToCall (function pointer)
Retn: none
Note: adapted from C++ Programming by D.S. Malik
================================================================*/
template <class T>
void Tree<T>::traversePostOrderR(nodeType<T>* current, const function<void(string, int)> &funcToCall)
{
	int height = 0;

	if (current != NULL)
	{
		height = nodeHeight(current);
		traversePostOrderR(current->left, funcToCall);
		traversePostOrderR(current->right, funcToCall);
		funcToCall(current->data, height);
	}
}

/*================================================================
Name: insert
Desc: inserts user's string(s) into the binary search tree
Args: data (string)
Retn: true if successful, false otherwise
Note: Adapted from C++ Programming by D.S. Malik
================================================================*/
template <class T>
bool Tree<T>::insert(T data)
{
	// initialize variables and allocate memory for new nodes
	nodeType<T>* currentNode = NULL; // pointer to traverse
	nodeType<T>* trailCurrent = NULL; // pointer to follow current

	nodeType<T>* newTreeNode = new nodeType<T>; // pointer to create node
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
	return false;

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
Name: deleteNode
Desc: deletes user entered node
Args: itemToDelete (string)
Retn: none
Note: Adapted from C++ Programming by D.S. Malik
================================================================*/
template <class T>
void Tree<T>::deleteNode(const T& itemToDelete)
{
	nodeType<T>* currentNode = NULL;
	nodeType<T>* trailCurrent = NULL;

	found = false;

	if (root == NULL)
	{
		cout << "Error! Cannot delete from an empty tree." << endl;
	}
	else
	{
		// start traversal from root of tree
		currentNode = root;
		trailCurrent = root;

		while (currentNode != nullptr && !found)
		{
			if (currentNode->data == itemToDelete)
			{
				found = true;
			}
			else
			{
				trailCurrent = currentNode;
				currentNode = search(currentNode, itemToDelete);
			}
		}
	}

	if (currentNode == NULL)
	{
		cout << "Error! The item to be deleted is not in the tree." << endl;
	}
	else if (found == true)
	{
		// case of deletions (listed in deleteFromTree)
		if (currentNode == root)
		{
			deleteFromTree(root);
		}
		else if (trailCurrent->data > itemToDelete)
		{
			deleteFromTree(trailCurrent->left);
		}
		else
		{
			deleteFromTree(trailCurrent->right);
		}
	}
	else
	{
		cout << "Error! The item to be deleted is not in the tree." << endl;
	}
}

/*================================================================
Name: removeTree
Desc: destroys tree
Args: 
Retn: none
================================================================*/
template <class T>
void Tree<T>::removeTree()
{
	removeAllNodes(root);
}

// ================================================ Private Function Class Implementation =========================================
// ================================================ Exluding Recursive Traversal Routines =========================================

/*================================================================
Name: deepCopy
Desc: creates a deepy copy of tree
Args: copiedTreeRoot (node*), ourTreeRoot (node*)
Retn: none
Note: adapted from C++ Programming by D.S. Malik
================================================================*/
template <class T>
void Tree<T>::deepCopy(nodeType<T>* &copiedTreeRoot, nodeType<T>* ourTreeRoot)
{
	if (ourTreeRoot == NULL)
	{
		copiedTreeRoot = NULL;
	}
	else
	{
		copiedTreeRoot = new nodeType<T>; // create node to traverse
		copiedTreeRoot->data = ourTreeRoot->data; // copy each piece of data
		deepCopy(copiedTreeRoot->left, ourTreeRoot->left); // copy left or right
		deepCopy(copiedTreeRoot->right, ourTreeRoot->right);
	}
}

/*================================================================
Name: search
Desc: searches for the itemToDelete
Args: currentNode (node*), itemToDelete (string)
Retn: a node to delete (node*)
================================================================*/
template <class T>
nodeType<T>* Tree<T>::search(nodeType<T>* currentNode, const T& itemToDelete)
{
	found = false;

	if (root == NULL)
	{
		cout << "Error! Cannot delete node from an empty tree." << endl;
	}

	if (currentNode == NULL) // base case
	{
		return currentNode;
	}
	else // general case
	{
		if (currentNode->data == itemToDelete)
		{
			return currentNode;
			found = true;
		}
		else if (currentNode->data > itemToDelete)
		{
			search(currentNode->left, itemToDelete);
		}
		else
		{
			search(currentNode->right, itemToDelete);
		}
	}
}

/*================================================================
Name: deleteFromTree
Desc: deletes user-entered node from tree
Args: nodePointer (node*)
Retn: none
Note: adapted from C++ Programming by D.S. Malik
================================================================*/
template <class T>
void Tree<T>::deleteFromTree(nodeType<T>* &nodePointer)
{
	nodeType<T>* currentNode;
	nodeType<T>* trailCurrent;
	nodeType<T>* nodeToDelete;

	// for each case of deletion:
	// (1) set the nodeToDelete to a temporary node
	// (2) update the pointers
	// (3) delete the temporary node

	// case 0: node is not in list
	if (nodePointer == NULL)
	{
		cout << "Error! The node to delete does not exist!" << endl;
	}
	// case 1: nodeToDelete is a leaf
	else if (nodePointer->left == NULL && nodePointer->right == NULL)
	{
		nodeToDelete = nodePointer;
		nodePointer = NULL;
		delete nodeToDelete;
	}
	// case 2: nodeToDelete has only a left child
	else if (nodePointer->right == NULL)
	{
		nodeToDelete = nodePointer;
		nodePointer = nodeToDelete->left;
		delete nodeToDelete;
	}
	// case 3: nodeToDelete has only a right child
	else if (nodePointer->left == NULL)
	{
		nodeToDelete = nodePointer;
		nodePointer = nodeToDelete->right;
		delete nodeToDelete;
	}
	// case 4: nodeToDelete has a left and right child
	else
	{
		currentNode = nodePointer->left;
		trailCurrent = NULL;

		while (currentNode->right != NULL)
		{
			trailCurrent = currentNode;
			currentNode = currentNode->right;
		}

		nodePointer->data = currentNode->data;

		if (trailCurrent == NULL)
		{
			nodePointer->left = currentNode->left;
		}
		else
		{
			trailCurrent->right = currentNode->left;
		}

		delete currentNode;
	}
}

/*================================================================
Name: nodeHeight
Desc: calculates the height of a node in the tree
Args: nodePointer (node*)
Retn: height (int)
Note: adapted from CS-260
================================================================*/
template<class T>
int Tree<T>::nodeHeight(nodeType<T> *nodePointer) const
{
	if (nodePointer == NULL)
		return 0;
	else
		return 1 + max(nodeHeight(nodePointer->left), nodeHeight(nodePointer->right));
}

/*================================================================
Name: removeAllNodes
Desc: deallocates memory & deletes all nodes from tree
Args: nodeToDelete (node*)
Retn: true if successful, false otherwise
================================================================*/
template <class T>
bool Tree<T>::removeAllNodes(nodeType<T>* &nodeToDelete)
{
	nodeType<T>* currentNode;
	nodeType<T>* trailCurrent = NULL;

	currentNode = root; // start from root

	// empty list (nothing remove)
	if (root == NULL)
	{
		return false;
	}

	if (nodeToDelete != NULL)
	{
		// remove all nodes from left and right of tree
		removeAllNodes(nodeToDelete->left);
		removeAllNodes(nodeToDelete->right);
		delete nodeToDelete;
		nodeToDelete = NULL;
		return true;
	}
	return false;
}