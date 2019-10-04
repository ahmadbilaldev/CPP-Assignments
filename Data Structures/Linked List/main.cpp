#include "list.cpp"
#include <iostream>

using namespace std;

int main()
{
	list linkList;

	linkList.insert(1);
	linkList.insert(2);
	linkList.insert(3);
	cout << "Nodes are:" << endl;
	linkList.print();

	cout << endl
		 << "Check the reverse function:" << endl;
	linkList.checkReverse();

	// 	linkList.insertAtBegin(50);
	// 	cout << endl
	// 		 << "Now after adding 50 at the beginning my Link List is" << endl;
	// 	linkList.print();

	// 	linkList.insertAtBegin(5);
	// 	cout << "Now after adding 5 at the beginning my Link List is" << endl;
	// 	linkList.print();

	// 	linkList.insertAtEnd(0);
	// 	cout << "Now after adding 0 at the end my Link List is" << endl;
	// 	linkList.print();

	// 	linkList.updateValueByIndex(201, 5);

	// 	cout << "Now after Updating a node having value of 200 at the 5th index in the list by new value 201 my Link List is" << endl;
	// 	linkList.print();

	// 	linkList.updateValue(99, 5);
	// 	cout << "Now after Updating a node having previous value of 5 in the list by new value 150 my Link List is" << endl;
	// 	linkList.print();
	// }
