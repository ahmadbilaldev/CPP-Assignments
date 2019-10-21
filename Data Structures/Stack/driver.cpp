/**
 * Driver program
 */

#include <iostream>
#include "cNode.h"
#include "cStack.h"
#include <fstream>

using namespace std;

int main()
{
    cStack stack;
    cNode node;

    // isEmpty and isNotEmpty checks.
    cout << "Check if Stack is empty or not: ";
    if (stack.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not Empty" << endl;
    }

    cout << "Check if Stack is not empty or empty: ";
    if (stack.isNotEmpty())
    {
        cout << "Stack is not empty" << endl;
    }
    else
    {
        cout << "Stack is Empty" << endl;
    }

    // Declaring a new node using constructor.

    cout << " Adding a new node: " << endl;

    cNode *ptr = new cNode(100);

    stack.push(ptr); // Pushing the new node in stack.

    // isEmpty and isNotEmpty checks.

    cout << "Check if Stack is empty or not: " << endl;
    if (stack.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not Empty" << endl;
    }

    // Printing.

    cout << "Print all nodes in the stack: ";
    stack.print();

    // Using setData to add new node.
    cout << "Adding a new node using setData()" << endl;
    cNode *node1 = new cNode();
    node1->setData(1);
    stack.push(node1);
    stack.print();

    // Adding more nodes.

    cout << "Adding more nodes: " << endl;
    cNode *node2 = new cNode();
    node2->setData(2);
    stack.push(node2);

    cNode *node3 = new cNode();
    node3->setData(3);
    stack.push(node3);

    cNode *node4 = new cNode();
    node4->setData(4);
    stack.push(node4);
    stack.print();

    // Deleting the first node in the stack using pop().

    cout << "Delete first node in the stack: " << endl;
    stack.pop();
    stack.print();

    // Using getter function to get value of a node.

    cout << "Using getter function to get value of a node: " << endl;
    cout << node4->getData();

    // Testing File I/O.
    ofstream outFile;
    outFile.open("file.txt");

    cout << "Writing to output file." << endl;
    if (outFile.is_open())
    {
        stack.writeToFile(outFile);
    }
    else
    {
        cout << "Error, file not opened." << endl;
    }

    outFile.close();

    ifstream inFile;
    inFile.open("input.txt");
    cStack testStack;

    if (inFile.is_open())
    {
        cout << "\nReading data of Stack1 from file data.txt" << endl;
        testStack.readFromFile(inFile);
        cout << "Done Reading from file !\n";
    }
    else
    {
        cout << "The file is not opened for the Read operation !" << endl;
    }

    cout << "Printing stack object Read from file" << endl;
    testStack.print();

    inFile.close();
}
