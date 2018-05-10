/*************************************************************
Name: BinarySearchTrees.h
Code: Kira Corbett
Date: 5/5/18
Desc: class definitions binary search trees.
**************************************************************/

#pragma once

#include <string>
#include <functional>

using namespace std;

class BinarySearchTrees
{
public:
	BinarySearchTrees();
	/*==================
	Desc: constructor
	==================*/

	~BinarySearchTrees();
	/*====================
	Desc: destructor
	====================*/

	bool insert(string userData);
	/*========================================================
	Desc: inserts user's string(s) into the binary search tree
	Retn: true if successful, false otherwise
	========================================================*/

	void printInOrder();
	/*========================================================
	Desc: recursive call to print in order
	Retn: none
	========================================================*/

	void printPreOrder();
	/*========================================================
	Desc: root, left, right (used for deletion)
	Retn: none
	========================================================*/

	void printPostOrder();
	/*========================================================
	Desc: left, right, root (used for copy)
	Retn: none
	========================================================*/

private:
	struct treeNode
	{
		string data;
		treeNode* left;
		treeNode* right;
	};

	treeNode* root;

	void printInOrderR(treeNode* current, const function<void(string)> &funcToCall);

	void printPreOrderR(treeNode* current, const function<void(string)> &funcToCall);

	void printPostOrderR(treeNode* current, const function<void(string)> &funcToCall);

	//template <class varType>
	//struct nodeType
	//{
	//	varType info;
	//	nodeType<varType>* left;
	//	nodeType<varType>* right;
	//};
};