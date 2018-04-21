/**************************************************
Name: StackTest.cpp
Code: Kira Corbett
Date: 4/18/18
Desc: Practice working with stacks by writing a
program that converts infix expressions to
postfix and then evaluates them.
***************************************************/
#include <iostream>
#include "Stacks.h"

using namespace std;

const string INFIX_1 = "5 # 2";
const string INFIX_2 = "5 * - 6 8";
const string INFIX_3 = "5*2  +   3";
const string INFIX_4 = "3 + 5 * (7-2)";
const string INFIX_5 = "3 + ( (8-5) * (4+9) )";

int main()
{
	Stacks infixExpressions;

	cout << "Author: Kira Corbett" << endl << endl;

	infixExpressions.expressionEvaluation(INFIX_1);
	infixExpressions.expressionEvaluation(INFIX_2);
	infixExpressions.expressionEvaluation(INFIX_3);
	infixExpressions.expressionEvaluation(INFIX_4);
	infixExpressions.expressionEvaluation(INFIX_5);

	cin.get();
	cin.ignore();

	return 0;
}