//This Program contains the list class. We declared insert, insert at end, insert at beginning, update value by index,
//update value by using previous value and print the link list

//Added node.cpp file
#include "node.cpp"
#include <iostream>

using namespace std;

//Declared class list in which we defined methods we want to implement on Link List
class list
{

	//Pointer which has the address of top
	node *headNode;

	//pointer which points to the current Node
	node *currentNode;

	// Size of Linked List
	int size;

public:
	// Sets all pointers to NULL and size to zero
	list()
	{
		headNode = NULL;
		currentNode = NULL;
		size = 0;
	}

	// Inserts a new node in the list
	void insert(int number)
	{
		if (currentNode != NULL)
		{
			if (currentNode->getNextNode() == 0) // If the current node is the last node of the list.
			{
				node *newNode = new node();
				currentNode->setNextNode(newNode);
				newNode->setPreviousNode(currentNode);
				currentNode = newNode;
				currentNode->setValue(number);
				currentNode->setNextNode(0);
				size++;
			}
			else
			{
				node *newNode = new node();
				newNode->setNextNode(currentNode->getNextNode());		// Sets the next node to the node after new node.
				currentNode->setNextNode(newNode);						// Sets the new node the node after current node.
				newNode->setPreviousNode(currentNode);					// Sets current node to the previous of new node.
				(currentNode->getNextNode())->setPreviousNode(newNode); // Sets the previous node of next node to incoming node.
				currentNode = newNode;
				currentNode->setValue(number);
				size++;
			}
		}
		else
		{
			node *temp = new node();
			headNode = temp;
			currentNode = headNode;
			currentNode->setValue(number);
			currentNode->setNextNode(0);
			currentNode->setPreviousNode(0);
			size++;
		}
	}

	// Inserts a new node at the start of Link List
	void insertAtBegin(int number)
	{

		start();
		node *temp = new node();
		temp->setNextNode(currentNode);
		currentNode = temp;
		headNode = temp;
		currentNode->setValue(number);
		size++;
	}

	// Inserts a new node at the end of Link List
	void insertAtEnd(int number)
	{
		start();
		for (int i = 0; i < size; i++)
		{
			move();
		}
		node *temp = new node();
		currentNode->setNextNode(temp);
		currentNode = temp;
		currentNode->setValue(number);
		currentNode->setNextNode(0);
		size++;
	}

	// Updates value of a node by using index of that node
	void updateValueByIndex(int newValue, int index)
	{
		start();
		for (int i = 0; i < index - 1; i++)
		{
			move();
		}
		currentNode->setValue(newValue);
	}

	// Updates value of a node by using previous value of that node
	void updateValue(int newValue, int previousValue)
	{
		start();
		while (currentNode->getNextNode() != 0)
		{
			if (currentNode->getValue() == previousValue)
			{
				currentNode->setValue(newValue);
				break;
			}
			move();
		}
	}

	// Gets size of Link List
	int getSize()
	{
		return size;
	}

	// Gets value of a specific node
	int get()
	{
		return currentNode->getValue();
	}

	// Moves at the start of the Link List
	void start()
	{
		currentNode = headNode;
	}

	// Moves to next Node
	void move()
	{
		if (currentNode->getNextNode() != 0)
		{
			currentNode = currentNode->getNextNode();
		}
	}

	void reverse()
	{
		if (currentNode->getPreviousNode() != 0)
		{
			currentNode = currentNode->getPreviousNode();
		}
	}

	void checkReverse()
	{
		cout << "Current Node is: " << currentNode->getValue();
		reverse();
		cout << endl
			 << "Current Node after reverse is: " << currentNode->getValue();
	}

	void print()
	{
		if (headNode == NULL)
		{
			cout << "Link List is empty";
		}
		else
		{
			start();
			for (int i = 0; i < size; i++)
			{
				cout << get() << endl;
				if (i < (size - 1))
				{
					move();
				}
			}
		}
	}

	/*	void ascendingSort() {
		int temp = 0;
		node *ptr = new node();
		ptr = headNode;
		start();
		for (int i = 0; i < size-1; i++) {
			move();
			for (int j = i + 1; j < size; j++) {
				if (currentNode->getValue() < ptr->getValue()) {
					temp = currentNode->getValue();
					currentNode->setValue(ptr->getValue());
					ptr->setValue(temp);
				}
			}
		}
	}
*/

	// void deleteNode(int valueOfNode)
	// {
	// 	start();
	// 	while (currentNode->getNextNode() != 0)
	// 	{
	// 		if (currentNode->getValue() == valueOfNode)
	// 		{
	// 			lastCurrentNode->setNextNode(currentNode->getNextNode());
	// 			delete currentNode;
	// 			currentNode = lastCurrentNode;
	// 			break;
	// 		}
	// 		move();
	// 	}
	// 	size--;
	// }
};
