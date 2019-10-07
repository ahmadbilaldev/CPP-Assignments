#include "list.cpp"
#include <iostream>

using namespace std;

int main()
{
	list linkList;

	// Insert Nodes.
	linkList.insert(1);
	linkList.insert(2);
	linkList.insert(3);
	cout << "Nodes are:" << endl;
	linkList.print();

	cout << endl
		 << "Check the reverse function:" << endl;
	linkList.checkReverse();

	linkList.insertAtStart(50);
	cout << endl
		 << "Adding 50 at the beginning" << endl;
	linkList.print();

	linkList.insertAtEnd(0);
	cout << "Adding 0 at the end" << endl;
	linkList.print();

	linkList.updateValueByIndex(9, 1);

	cout << "Updating the 5th node in the list by new value 9" << endl;
	linkList.print();

	// 	linkList.updateValue(99, 5);
	// 	cout << "Now after Updating a node having previous value of 5 in the list by new value 150 my Link List is" << endl;
	// 	linkList.print();
}
