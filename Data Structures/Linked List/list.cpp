/**
 * List Class. Uses node class to initialize a list of nodes.
 */
#include "node.cpp"
#include <iostream>

using namespace std;

class list
{
	// Has the address of the first/top node.
	node *headNode;

	node *currentNode;

	// Size of the Linked List
	int size;

public:
	list() // Sets all pointers to NULL and size to zero
	{
		headNode = NULL;
		currentNode = NULL;
		size = 0;
	}

	void start() // Moves the current node to start of the list.
	{
		currentNode = headNode;
	}

	void move() // Moves current node to the next node.
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

	/**
	 * Setter Functions.
	 */
	void insert(int number) // Inserts a new node in the list.
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
			else // If the current node is somewhere in the middle.
			{
				node *newNode = new node();
				newNode->setNextNode(currentNode->getNextNode());		// Sets the next node to the node after new node.
				currentNode->setNextNode(newNode);						// Sets the new node the node after current node.
				newNode->setPreviousNode(currentNode);					// Sets current node to the previous of new node.
				(currentNode->getNextNode())->setPreviousNode(newNode); // Sets the previous node of next node to new node.
				currentNode = newNode;
				currentNode->setValue(number);
				size++;
			}
		}
		else // If the incoming node is the first node in the list.
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

	void insertAtStart(int number) // Inserts a new node at the start of the list.
	{
		start();
		node *newNode = new node();
		newNode->setNextNode(currentNode);
		currentNode = newNode;
		headNode = newNode;
		currentNode->setValue(number);
		size++;
	}

	void insertAtEnd(int number) // Inserts a new node at the end of the list.
	{
		start();
		for (int i = 0; i < size; i++)
		{
			move();
		}
		node *newNode = new node();
		currentNode->setNextNode(newNode);
		newNode->setPreviousNode(currentNode);
		currentNode = newNode;
		currentNode->setValue(number);
		currentNode->setNextNode(0);
		size++;
	}

	void updateValueByIndex(int newValue, int index) // Updates value of a node by using its index.
	{
		start();
		for (int i = 0; i < index; i++)
		{
			move();
		}
		currentNode->setValue(newValue);
	}

	void updateValue(int newValue, int previousValue) // Updates value of a node using previous value.
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
				cout << currentNode->getValue() << endl;
				if (i < (size - 1))
				{
					move();
				}
			}
		}
	}

	void printReverse()
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
				move();
			}

			cout << currentNode->getValue() << endl;
			if (i < (size - 1))
			{
				move();
			}
		}
	}

	void checkReverse()
	{
		cout << "Current Node is: " << currentNode->getValue();
		reverse();
		cout << endl
			 << "Current Node after reverse is: " << currentNode->getValue();
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
