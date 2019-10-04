/*
Node Class.
*/

#include <iostream>

using namespace std;

class node
{
	int value;
	node *nextNode;
	node *previousNode;

public:
	/**
	 * Setter Functions
	 */
	void setValue(int v)
	{
		value = v;
	}

	void setNextNode(node *newNode)
	{
		nextNode = newNode;
	}

	void setPreviousNode(node *newNode)
	{
		previousNode = newNode;
	}

	/**
	 * Getter Functions.
	 */
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
