/**************************************************
Name: Stacks.cpp
Code: Kira Corbett
Date: 4/18/18
Desc: Implementation for Stacks class
***************************************************/
#include "Stacks.h"

Stacks::Stacks()
{

}

Stacks::~Stacks()
{

}

/*================================================================
Name: expressionEvaluation
Desc: evaluates infix and converts to postfix
Args: infix (string)
Retn: none
================================================================*/
void Stacks::expressionEvaluation(std::string infix)
{
	std::string infixNoSpace;
	std::string postfix;

	std::cout << "Processing " << infix << std::endl;

	infixNoSpace = removeSpace(infix);

	std::cout << "Infix: " << infixNoSpace << std::endl;

	// check validity of infix expression
	if (isValid(infixNoSpace) == true)
	{
		// if it is valid, convert to postfix
		postfix = convertToPostfix(infixNoSpace);
		std::cout << "Postfix: " << postfix << std::endl;
		std::cout << "Result: " << evaluatePostfix(postfix) << std::endl;
	}
	else
	{
		// print out an error
		std::cout << "ERROR" << std::endl;
	}

	std::cout << std::endl;
}


/*================================================================
Name: removeSpace
Desc: removes any white space inputted from user
Args: infixSpace (string)
Retn: infixNoSpace (string)
================================================================*/
std::string Stacks::removeSpace(std::string infixSpace)
{
	std::string infixNoSpace;

	// check for a tab or space
	while ((infixSpace.find('\t') != std::string::npos) || (infixSpace.find(' ') != std::string::npos))
	{
		// traverse through string to find tab or space
		for (int i = 0; i < infixSpace.length(); i++)
		{
			if (infixSpace[i] == '\t' || infixSpace[i] == ' ')
			{
				// if there is a spacing, erase it
				infixSpace.erase(i, 1);
			}
		}
	}

	// infix now becomes an infix with no space
	infixNoSpace = infixSpace;

	return infixNoSpace;
}

/*================================================================
Name: isValid
Desc: verifies string doesn't contain invalid chars
Args: infixNoSpace (string)
Retn: true if successful, false otherwise
================================================================*/
bool Stacks::isValid(std::string infixNoSpace)
{
	// if there is an empty string, return false
	if (infixNoSpace == "")
	{
		return false;
	}

	// traverse through string to verify validity of actions
	for (int i = 0; i < infixNoSpace.length(); i++)
	{
		// if the infix string does not contain a OPERATOR and an OPERAND, it is not valid
		if ((infixNoSpace[i] != '(' && infixNoSpace[i] != ')' && infixNoSpace[i] != '*' && infixNoSpace[i] != '+' && infixNoSpace[i] != '-' &&
			infixNoSpace[i] != '/') && (infixNoSpace[i] < 48 || infixNoSpace[i] > 57))
		{
			return false;
		}

		// if the infix contains two operators consecutively, it is not valid
		if ((infixNoSpace[i] == '*' || infixNoSpace[i] == '+' || infixNoSpace[i] == '-' || infixNoSpace[i] == '/') &&
			(infixNoSpace[i - 1] == '*' || infixNoSpace[i - 1] == '+' || infixNoSpace[i - 1] == '-' || infixNoSpace[i - 1] == '/'))
		{
			return false;
		}
	}
	return true;
}

/*================================================================
Name: convertToPostfix
Desc: converts infix expression to postfix
Args: infixNoSpace (string)
Retn: postfix (string)
Algorithm Adapted from Jen Miller's CS-260 Class
================================================================*/
std::string Stacks::convertToPostfix(std::string infixNoSpace)
{
	// initialize string to nothing
	std::string postfix = "";

	for (int i = 0; i < infixNoSpace.length(); i++)
	{
		// if operator is a '('
		if (infixNoSpace[i] == '(')
		{
			// push onto the operator stack
			operatorStack.push(infixNoSpace[i]);
		}

		// if operator is a ')'
		if (infixNoSpace[i] == ')')
		{
			while (operatorStack.top() != '(')
			{
				// top & pop the stack until a matching '(' is found
				postfix += operatorStack.top();
				operatorStack.pop();
			}

			// we don't print the remaining '('
			operatorStack.pop();
		}

		// if we identify an operand (integer)
		if (infixNoSpace[i] >= 48 && infixNoSpace[i] <= 57)
		{
			// it becomes apart of the postfix expression
			postfix += infixNoSpace[i];
		}

		// if we identify an operator
		if (infixNoSpace[i] == '+' || infixNoSpace[i] == '-' || infixNoSpace[i] == '*' || infixNoSpace[i] == '/')
		{
			// push the operator onto the stack if it is empty
			if (!operatorStack.empty())
			{
				// else circulate; top & pop the stack
				while (operatorStack.empty() != true && isPrecendence(infixNoSpace[i], operatorStack.top()))
				{
					// the "top" method just gets a copy of what's on top; it doesn't remove it
					postfix += operatorStack.top();
					operatorStack.pop();
				}

				// push contents onto stack
				operatorStack.push(infixNoSpace[i]);
			}
			else
			{
				// other cases can be pusphed onto the stack
				operatorStack.push(infixNoSpace[i]);
			}
		}
	}

	// pop remaining contents on stack until it is empty
	while (!operatorStack.empty())
	{
		postfix += operatorStack.top();
		operatorStack.pop();
	}

	return postfix;
}

/*================================================================
Name: evaluatePostfix
Desc: evaluates postfix expression
Args: postfix (string)
Retn: solution (int)
================================================================*/
int Stacks::evaluatePostfix(std::string postfix)
{
	int num1 = 0;
	int num2 = 0;
	int solution = 0;

	char intDigit;

	for (int i = 0; i < postfix.length(); i++)
	{
		// if expression contains an integer
		if (postfix[i] >= 48 && postfix[i] <= 57)
		{
			// identify and declare the single char of string
			// push onto the stack
			intDigit = postfix[i];
			operandStack.push(std::stoi(&intDigit));
		}

		// if the epxression contains an operator
		if (postfix[i] == '*' || postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '/')
		{
			// top and pop the stack twice
			// compute expression
			// push result onto the stack
			switch (postfix[i])
			{
			case '*':
				// top and pop stack twice
				num1 = operandStack.top();
				operandStack.pop();

				num2 = operandStack.top();
				operandStack.pop();

				// perform calculation
				solution = num1 * num2;

				// push result onto stack
				operandStack.push(solution);
				break;
			case '+':
				// top and pop stack twice
				num1 = operandStack.top();
				operandStack.pop();

				num2 = operandStack.top();
				operandStack.pop();

				// perform calculation
				solution = num1 + num2;

				// push result onto stack
				operandStack.push(solution);
				break;
			case '-':
				// top and pop stack twice
				num1 = operandStack.top();
				operandStack.pop();

				num2 = operandStack.top();
				operandStack.pop();

				// perform calculation
				solution = num2 - num1;

				// push result onto stack
				operandStack.push(solution);
				break;
			case '/':
				// top and pop stack twice
				num1 = operandStack.top();
				operandStack.pop();

				num2 = operandStack.top();
				operandStack.pop();

				// perform calculation
				solution = num1 / num2;

				// push result onto stack
				operandStack.push(solution);
				break;
			}
		}
	}

	return solution;
}

/*================================================================
Name: isPrecendence
Desc: identifies and implements order of operations
Args: operator1 (char&), operator2 (char&)
Retn: true if successful, false otherwise
================================================================*/
bool Stacks::isPrecendence(char& operator1, char& operator2)
{
	if (operator2 == '(' || operator2 == ')')
	{
		return false;
	}

	if ((operator1 == '*' || operator1 == '/') && (operator2 == '+' || operator2 == '-'))
	{
		return false;
	}
	else return true;
}