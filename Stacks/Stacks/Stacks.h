/**************************************************
Name: Stacks.h
Code: Kira Corbett
Date: 4/18/18
Desc: Class definitions for the Stack class
***************************************************/
#pragma once

#include <iostream>
#include <string>
#include <stack>


class Stacks
{
public:
	Stacks();
	/*==================================================
	Desc: default constructor
	===================================================*/

	~Stacks();
	/*==================================================
	Desc: destructor
	===================================================*/

	void expressionEvaluation(std::string infix);
	/*==================================================
	Desc: evaluates infix and converts to postfix
	Retn: none
	===================================================*/

	std::string removeSpace(std::string infix);
	/*==================================================
	Desc: removes any white space inputted from user
	Retn: infixNoSpace (string)
	===================================================*/

	bool isValid(std::string infixNoSpace);
	/*==================================================
	Desc: verifies string doesn't contain invalid chars
	Retn: true if successful, false otherwise
	===================================================*/

	std::string convertToPostfix(std::string infixNoSpace);
	/*==================================================
	Desc: converts infix expression to postfix
	Retn: postfix (string)
	===================================================*/

	int evaluatePostfix(std::string postfix);
	/*==================================================
	Desc: evaluates postfix expression
	Retn: solution (int)
	===================================================*/

	bool isPrecendence(char& operator1, char& operator2);
	/*==================================================
	Desc: identifies and implements order of operations
	Retn: true if successful, false otherwise
	===================================================*/

private:

	// stacks for operands and operators
	std::stack<int> operandStack;
	std::stack<char> operatorStack;
};
