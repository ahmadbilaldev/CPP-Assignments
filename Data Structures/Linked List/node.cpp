// DSA Lab 2.cpp : This program is about linked list.
//

#include <iostream>

using namespace std;

//Declaring a node class
class node
{

	//Declaring private data members
	int value;
	node *nextNode;
	node *previousNode;

public:
	//declaring a function which sets the value in the node
	void setValue(int v)
	{
		value = v;
	}

	//Function used to move to next Node
	void setNextNode(node *nn)
	{
		nextNode = nn;
	}

	//Function used to move to previous Node
	void setPreviousNode(node *nn)
	{
		previousNode = nn;
	}

	// Returns the value stored in a node
	int getValue()
	{
		return value;
	}

	node *getNextNode()
	{
		return nextNode;
	}

	node *getPreviousNode()
	{
		return previousNode;
	}
};
