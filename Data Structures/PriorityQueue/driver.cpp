#include <iostream>
#include "cNode.h"
#include "cStack.h"
#include "cQueue.h"
#include "cPriorityQueue.h"

using namespace std;

int main()
{
    cPriorityQueue pq;

    // Checks.
    cout << "isEmpty check: " << endl;
    if (pq.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
    cout << "isNotEmpty check: " << endl;
    if (pq.isNotEmpty())
    {
        cout << "Queue is not empty" << endl;
    }
    else
    {
        cout << "Queue is Empty" << endl;
    }

    // Printing.
    cout << "Nodes in Prioirity Queue are: " << endl;
    pq.print();

    // Declaring a node and setting its priority.

    cNode *ptr = new cNode(110);
    ptr->setPriority(2);

    pq.addInPriorityQue(ptr); // Pushing the node in priority queue.

    // Checks.
    cout << "isEmpty check: " << endl;
    if (pq.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    // Printing.
    cout << "Nodes in Prioirity Queue are: " << endl;
    pq.print();

    // Deleting the node.
    pq.removeFromPriorityQue();

    cout << "Priority Queue after deleting the node: " << endl;
    if (pq.isEmpty())
    {
        cout << "Priority Queue is empty.";
    }
    else
    {
        pq.print();
    }

    // Adding more nodes using setter function.
    cNode *node1 = new cNode();
    node1->setData(1);
    node1->setPriority(9);
    pq.addInPriorityQue(node1);

    cNode *node2 = new cNode();
    node2->setData(2);
    node2->setPriority(3);
    pq.addInPriorityQue(node2);

    cNode *node3 = new cNode();
    node3->setData(3);
    node3->setPriority(15);
    pq.addInPriorityQue(node3);

    cNode *node4 = new cNode();
    node4->setData(4);
    node4->setPriority(5);
    pq.addInPriorityQue(node4);

    cNode *node5 = new cNode();
    node5->setData(5);
    node5->setPriority(2);
    pq.addInPriorityQue(node5);

    cNode *node6 = new cNode();
    node6->setData(6);
    node6->setPriority(50);
    pq.addInPriorityQue(node6);

    cout << "Priority Queue after adding multiple nodes: " << endl;
    if (pq.isNotEmpty())
        pq.print();

    // Checking delete function.
    cout << "Prioirity Queue after deleting the first node: " << endl;
    pq.removeFromPriorityQue();
    if (pq.isNotEmpty())
        pq.print();

    // Copy constructor.
    cPriorityQueue queueDestination(pq);

    cout << "Using copy constructor, old queue is copied in a new queueDestination: ";
    queueDestination.print();

    // Assignment Operator
    cout << "Using assignment operator to copy queueDestination to another queue: " << endl;
    cPriorityQueue queue1 = queueDestination;
    queue1.print();

    system("pause");
}
