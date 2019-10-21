#include "cList.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cList linkedList;
    cNode node;

    // Checks.
    cout << "isEmpty check: " << endl;
    if (linkedList.isEmpty())
    {
        cout << "Linked List is empty" << endl;
    }
    else
    {
        cout << "Linked List is not Empty" << endl;
    }
    cout << "isNotEmpty check: " << endl;
    if (linkedList.isNotEmpty())
    {
        cout << "Linked List is not empty" << endl;
    }
    else
    {
        cout << "Linked List is Empty" << endl;
    }

    // Printing.
    cout << "Nodes in Linked List are: " << endl;
    linkedList.print();

    // Declaring a node and setting its data through constructor.
    cNode *ptr = new cNode(110);
    cout << "Adding a node." << endl;
    // Inserting into list.
    linkedList.insert(ptr);

    // Checks.
    cout << "isEmpty check: " << endl;
    if (linkedList.isEmpty())
    {
        cout << "Linked List is empty" << endl;
    }
    else
    {
        cout << "Linked List is not Empty" << endl;
    }

    // Printing.
    cout << "Nodes in the Linked List are: " << endl;
    linkedList.print();

    // Testing remove function
    linkedList.remove();
    cout << "After deleting the node: " << endl;
    if (linkedList.isNotEmpty())
        linkedList.print();

    // Adding more nodes using setter funtion.
    cNode *node1 = new cNode();
    node1->setData(1);
    linkedList.insert(node1);

    cNode *node2 = new cNode();
    node2->setData(2);
    linkedList.insert(node2);

    cNode *node3 = new cNode();
    node3->setData(3);
    linkedList.insert(node3);

    cNode *node4 = new cNode();
    node4->setData(4);
    linkedList.insert(node4);

    cNode *node5 = new cNode();
    node5->setData(5);
    linkedList.insert(node5);

    cNode *node6 = new cNode();
    node6->setData(6);
    linkedList.insert(node6);

    cout << "Linked list after inserting multiple nodes: " << endl;
    if (linkedList.isNotEmpty())
        linkedList.print();

    // Testing delete function.
    cout << "Deleting the first node: " << endl;
    linkedList.remove();
    if (linkedList.isNotEmpty())
        linkedList.print();

    // Insert at specific position.
    cNode *node7 = new cNode(120);
    linkedList.insertAt(2, node7);

    cout << "Adding a new node of value 120 at specific index i.e., 2: " << endl;
    if (linkedList.isNotEmpty())
        linkedList.print();

    // Delete at specific index.
    cout << "Deleting the node at index 4: ";
    linkedList.removeAt(4);
    if (linkedList.isNotEmpty())
        linkedList.print();

    // Swapping nodes.
    cout << "Swapping 6th node with 4th node" << endl;
    linkedList.swapNodesAt(6, 4);
    if (linkedList.isNotEmpty())
        linkedList.print();

    // Reversing the linkedList.
    cout << "Linked List after reverse: ";
    linkedList.reverse();
    if (linkedList.isNotEmpty())
        linkedList.print();

    // Copy constructor.
    cList newList(linkedList);
    cout << "Copy constuctor copies old list into newList:" << endl;
    newList.print();

    // Assignment operator.
    cList listDestination = newList;
    cout << "Using assinemnt operator to copy old list to a new listDestination: " << endl;
    if (listDestination.isNotEmpty())
        listDestination.print();

    system("pause");

    return 0;
}
