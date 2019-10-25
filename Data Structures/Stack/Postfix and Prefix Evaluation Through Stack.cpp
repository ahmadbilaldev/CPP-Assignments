// Postfix and Prefix Evaluation Through Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "cStack.h"
using namespace std;
cStack & cStack::postFixEvaluation(string expr)						//For Post fix evaluation
{
	cNode *ptr = new cNode();											          //pushing operands to stack using node ptr				
	cNode *result = new cNode();										        //for pushing saving result
	for (int i = 0; i != (expr.length()); i++)
	{
		int num = 0;
		if (expr[i] == ' ')										              	//handling exception for space after operator
		{
			i++;
		}
		if (isdigit(expr[i]))										              //seperating numbers from string with the help of space
		{
			while (isdigit(expr[i]))
			{
				num = (num * 10) + (expr[i] - 48);
				i++;
			}
			i--;
			ptr->setData(num);
			this->push(*&ptr);										              //after seperating numbers pushing them to stack
			ptr = new cNode();
		}
		else														                      //as an operator comes tpoping the last two operands
		{															                        //from stack and performing that operation
			switch (expr[i])
			{
			case '+':
			{
				cNode *op2 = new cNode();
				op2 = this->pop();
				cNode *op1 = new cNode();
				op1 = this->pop();
				result->setData(result->getData() + (op1->getData() + op2->getData()));
				this->push(*&result);							            	//after performing operation pushing result to stack 
																	                      //for further operations or for saving result
				result = new cNode();
				break;
			}
			case '-':
			{
				cNode *op2 = new cNode();
				op2 = this->pop();
				cNode *op1 = new cNode();
				op1 = this->pop();
				result->setData(result->getData() + (op1->getData() - op2->getData()));
				this->push(*&result);							          	//after performing operation pushing result to stack 
																                    	//for further operations or for saving result
				result = new cNode();
				break;
			}
			case '*':
			{
				cNode *op2 = new cNode();
				op2 = this->pop();
				cNode *op1 = new cNode();
				op1 = this->pop();
				result->setData(result->getData() + (op1->getData() * op2->getData()));
				this->push(*&result);							        	//after performing operation pushing result to stack 
																	                  //for further operations or for saving result
				result = new cNode();
				break;
			}
			case '/':
			{
				cNode *op2 = new cNode();
				op2 = this->pop();
				cNode *op1 = new cNode();
				op1 = this->pop();
				result->setData(result->getData() + (op1->getData() / op2->getData()));
				this->push(*&result);								      //after performing operation pushing result to stack 
																	                //for further operations or for saving result
				result = new cNode();
				break;
			}
			case '%':
			{
				cNode *op2 = new cNode();
				op2 = this->pop();
				cNode *op1 = new cNode();
				op1 = this->pop();
				result->setData(result->getData() + (op1->getData() % op2->getData()));
				this->push(*&result);							  	//after performing operation pushing result to stack 
																	            //for further operations or for saving result
				result = new cNode();
				break;
			}
			case '(':
			{
				i++;
				break;
			}
			case ')':
			{
				i++;
				break;
			}
			case'^':											        	//Exponential case
			{
				cNode *op2 = new cNode();
				op2 = this->pop();
				cNode *op1 = new cNode();
				op1 = this->pop();
				int mul = 1;
				for (int j = 0; j < (op2->getData()); j++)
				{
					mul = mul * (op1->getData());
				}
				result->setData(result->getData() + mul);
				this->push(*&result);								//after performing operation pushing result to stack 
																          	//for further operations or for saving result
				result = new cNode();
				break;
			}
			default:
			{
				cout << "Invalid Operation\n";
				break;
			}
			}
		}
	}
	return *this;
}
bool cStack::postfixPreCondition(string expr) const
{
	int is_digit = 0;
	int num = 0;
	while (expr[0] == ' ')
	{
		expr = expr.substr(1);
	}
	if (!(isdigit(expr[0])))										//To check at first of expression there is digit if not then return false
	{
		return false;
	}
	if (isdigit(expr[(expr.length() - 1)]))
	{
		return false;
	}
	for (int i = 0; i != (expr.length()); i++)
	{
		if (isdigit(expr[i]))										//seperating numbers from string with the help of space
		{
			while (isdigit(expr[i]))
			{
				num = (num * 10) + (expr[i] - 48);
				i++;
			}
			is_digit++;											  	//after seperating numbers pushing them to stack
		}
		if ((expr[i] == '+') || (expr[i] == '^') || (expr[i] == '-') || (expr[i] == '*') || (expr[i] == '/'))
		{															        //After getting an operator
			if (is_digit >= 2)									//it will check the no. of operators are greater than or equal to 2
			{														        //as all of the above operator requires two operands
				is_digit--;										  	//after getting satisfaction of operand it will decrease a no of operand
																	        //as after solving the operator with 2 operands the will be 1 operand left 
																	        //that will be their result therefore reducing 2 to 1 digit--
			}
			else													      // if # of operands according to operator does not satisfy it will return false
			{
				return false;
			}
		}
	}
	if ((((expr[(expr.length() - 1)]) == '+') || (expr[(expr.length() - 1)]) == '^' ||
		(expr[(expr.length() - 1)]) == '-' || (expr[(expr.length() - 1)]) == '*' || (expr[(expr.length() - 1)]) == '/'))
	{																      //after checking at the last of expression there is operator
		if (is_digit >= 2)									//checking the no of operands if the # the no. of operands are greater then 2
		{															      //it will return false as these operator uses only 2 operand here we used equal to
																      	// 2 in the condition too thats bcz the loop has already decreased is digit by 1
			return false;
		}
	}
	return true;
}
bool cStack::prefixPreCondition(string expr) const
{
	int is_digit = 0;
	int num = 0;
	if (isdigit(expr[0]))								//To check at first of expression there is digit if yes then return false
	{
		return false;
	}
	if ((((expr[(expr.length() - 1)]) == '+') || (expr[(expr.length() - 1)]) == '^' ||
		(expr[(expr.length() - 1)]) == '-' || (expr[(expr.length() - 1)]) == '*' || (expr[(expr.length() - 1)]) == '/'))
	{
		return false;
	}
	for (int i = (expr.length() - 1); i != -1; i--)
	{
		if (isdigit(expr[i]))							//seperating numbers from string with the help of space
		{
			int unit = 1;
			while (isdigit(expr[i]))
			{
				num = (num)+((expr[i] - 48)*unit);
				unit *= 10;
				i--;
			}
			is_digit++;											//after seperating numbers pushing them to stack
		}
		if ((expr[i] == '+') || (expr[i] == '^') || (expr[i] == '-') || (expr[i] == '*') || (expr[i] == '/'))
		{														  	//After getting an operator
			if (is_digit >= 2)						//it will check the no. of operators are greater than or equal to 2
			{														  //as all of the above operator requires two operands
				is_digit--;									//after getting satisfaction of operand it will decrease a no of operand
																   	//as after solving the operator with 2 operands the will be 1 operand left 
																  	//that will be their result therefore reducing 2 to 1 digit--
			}
			else													// if # of operands according to operator does not satisfy it will return false
			{
				return false;
			}
		}
	}
	if (((expr[0]) == '+') || ((expr[0]) == '^') || ((expr[0]) == '-') || ((expr[0]) == '*') || ((expr[0]) == '/'))
	{																//after checking at the last of expression there is operator
		if (is_digit >= 2)						//checking the no of operands if the # the no. of operands are greater then 2
		{															//it will return false as these operator uses only 2 operand here we used equal to
																	// 2 in the condition too thats bcz the loop has already decreased is digit by 1
			return false;
		}
	}
	return true;
}
cStack & cStack::preFixEvaluation(string expr)						//For Post fix evaluation
{

	cNode *ptr = new cNode();											  //pushing operands to stack using node ptr				
	cNode *result = new cNode();										//for pushing saving result
	for (int i = (expr.length() - 1); i != -1; i--)
	{
		int num = 0;
		if (expr[i] == ' ')											//handling exception for space after operator
		{
			i--;
		}
		if (isdigit(expr[i]))										//seperating numbers from string with the help of space
		{
			int unit = 1;
			while (isdigit(expr[i]))
			{
				num = (num)+((expr[i] - 48)*unit);
				unit *= 10;
				i--;
			}
			i++;
			ptr->setData(num);
			this->push(*&ptr);										//after seperating numbers pushing them to stack
			ptr = new cNode();
		}
		else													        	//as an operator comes tpoping the last two operands
		{														          	//from stack and performing that operation
			switch (expr[i])
			{
			case '+':
			{
				cNode *op1 = new cNode();
				op1 = this->pop();
				cNode *op2 = new cNode();
				op2 = this->pop();
				result->setData(result->getData() + (op1->getData() + op2->getData()));
				this->push(*&result);								//after performing operation pushing result to stack 
																          	//for further operations or for saving result
				result = new cNode();
				break;
			}
			case '-':
			{
				cNode *op1 = new cNode();
				op1 = this->pop();
				cNode *op2 = new cNode();
				op2 = this->pop();
				result->setData(result->getData() + (op1->getData() - op2->getData()));
				this->push(*&result);								//after performing operation pushing result to stack 
																	          //for further operations or for saving result
				result = new cNode();
				break;
			}
			case '*':
			{
				cNode *op1 = new cNode();
				op1 = this->pop();
				cNode *op2 = new cNode();
				op2 = this->pop();
				result->setData(result->getData() + (op1->getData() * op2->getData()));
				this->push(*&result);								//after performing operation pushing result to stack 
																          	//for further operations or for saving result
				result = new cNode();
				break;
			}
			case '/':
			{
				cNode *op1 = new cNode();
				op1 = this->pop();
				cNode *op2 = new cNode();
				op2 = this->pop();
				result->setData(result->getData() + (op1->getData() / op2->getData()));
				this->push(*&result);								//after performing operation pushing result to stack 
																          	//for further operations or for saving result
				result = new cNode();
				break;
			}
			case '%':
			{
				cNode *op1 = new cNode();
				op1 = this->pop();
				cNode *op2 = new cNode();
				op2 = this->pop();
				result->setData(result->getData() + (op1->getData() % op2->getData()));
				this->push(*&result);								//after performing operation pushing result to stack 
																	          //for further operations or for saving result
				result = new cNode();
				break;
			}

			case '(':
			{

				i--;
				break;
			}
			case ')':
			{
				i--;
				break;
			}
			case'^':										        		//Exponential case
			{
				cNode *op1 = new cNode();
				op1 = this->pop();
				cNode *op2 = new cNode();
				op2 = this->pop();
				int mul = 1;
				for (int j = 0; j < (op2->getData()); j++)
				{
					mul = mul * (op1->getData());
				}
				result->setData(result->getData() + mul);
				this->push(*&result);								//after performing operation pushing result to stack 
																	          //for further operations or for saving result
				result = new cNode();
				break;
			}
			default:
			{
				cout << "Invalid Operation\n";
				break;
			}
			}
		}
	}
	return *this;
}
