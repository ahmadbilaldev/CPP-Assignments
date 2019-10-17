#include "doubleList.cpp"
#include <iostream>

using namespace std;

int main()
{
	doubleList linkList;

	// Insert Nodes.
	linkList.insert(0);
	linkList.insert(1);
	linkList.insert(2);
	cout << "Nodes are:" << endl;
	linkList.print();

	linkList.insertAtStart(1);
	cout << endl
		 << "Adding 1 at the beginning" << endl;
	linkList.print();

	linkList.insertAtEnd(0);
	cout << "Adding 0 at the end" << endl;
	linkList.print();

	linkList.updateValueByIndex(9, 2);

	cout << "Updating value of the 3rd node to 9" << endl;
	linkList.print();

	linkList.updateValue(77, 1);
	cout << "Updating a node value of 1 with 77" << endl;
	linkList.print();

	cout << "Deleting the node with value 77: ";
	linkList.deleteNodeByValue(77);
	linkList.print();

	cout << "Deleting the first node: ";
	linkList.deleteNodeByPosition(1);
	linkList.print();
}
