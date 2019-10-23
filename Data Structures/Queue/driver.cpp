#include <iostream>
#include "cNode.h"
#include "cStack.h"
#include "cQueue.h"

using namespace std;

int main()
{
    cQueue queue;

    // isEmpty and isNotEmpty checks.
    cout << "Check if Queue is empty or not: " << endl;
    if (queue.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not Empty" << endl;
    }

    cout << "Check if Queue is not empty or empty: " << endl;
    if (queue.isNotEmpty())
    {
        cout << "Queue is not empty" << endl;
    }
    else
    {
        cout << "Queue is Empty" << endl;
    }

    // Declaring a new node using constructor.

    cNode *ptr = new cNode(110);
    queue.add(ptr); // Adding to queue.

    // Print the Queue.

    queue.print();

    // Delete the node.

    queue.remove();

    cout << "Deleting the node from Queue" << endl;
    queue.print();

    // isEmpty and isNotEmpty checks.

    cout << "Check if Queue is empty or not: " << endl;
    if (queue.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not Empty" << endl;
    }

    // Using setData to add new node.

    cNode *node1 = new cNode();
    node1->setData(1);
    queue.add(node1);
    cout << "Using setData to add new node." << endl;
    queue.print();

    // Adding more nodes.

    cNode *node2 = new cNode();
    node2->setData(2);
    queue.add(node2);

    cNode *node3 = new cNode();
    node3->setData(3);
    queue.add(node3);

    cNode *node4 = new cNode();
    node4->setData(4);
    queue.add(node4);

    // Printing Queue.

    if (queue.isNotEmpty())
        queue.print();

    // Deleting the first node in the Queue using remove().

    cout << "Deleting the first node in the Queue using remove()" << endl;
    queue.remove();
    if (queue.isNotEmpty())
        queue.print();

    // Using getter function to get value of a node.

    cout << "Using getter function to get value of a node: ";
    cout << node1->getData() << endl;

    // Copy constructor.
    cQueue queueDestination(queue);

    cout << "After using copy constructor to copy queue into queueDestination: ";
    queueDestination.print();

    // Assignment operator.
    cout << "Using assignemnt operator to copy old stack to a new stack: " << endl;
    cQueue queueDestination2 = queueDestination;
    queueDestination2.print();
}
