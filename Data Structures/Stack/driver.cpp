/**
 * Driver program
 */

#include <iostream>
#include "cNode.h"
#include "cStack.h"
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cStack *s1 = new cStack();
	string stri;
	cout << "\nInput postfix expression\n";							//taking string input from user
	getline(cin, stri, '\n');
	bool flag;
	flag = (s1->postfixPreCondition(stri));
	do
	{
		if (!flag)
		{
			cout << "Wrong post fix expression";
			cout << "\nInput postfix expression\n";							//taking string input from user
			getline(cin, stri, '\n');
			flag = (s1->postfixPreCondition(stri));
		}
	} while ((!flag));
	s1->postFixEvaluation(stri);
	cout << "\nResult of Post fix Evaluation on Stack s1 is: " << s1->pop()->getData();
	cout << "\nInput prefix expression \n";							//taking string input from user
	getline(cin, stri, '\n');
	flag = (s1->prefixPreCondition(stri));
	do
	{
		if (!flag)
		{
			cout << "Wrong pre fix expression";
			cout << "\nInput prefix expression\n";							//taking string input from user
			getline(cin, stri, '\n');
			flag = (s1->prefixPreCondition(stri));
		}
	} while ((!flag));
	s1->preFixEvaluation(stri);
	cout << "\nResult of Pre fix Evaluation on Stack s1 is: " << s1->pop()->getData();
	
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
    node4=new cNode();
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
        testStack.readFromFile(inFile);
    }
    else
    {
        cout << "Error, file not opened.!" << endl;
    }

    cout << "Reading from file." << endl;
    testStack.print();

    inFile.close();

    // Copy constructor.
    cout << "Copy constuctor to copy old stack into a new one:" << endl;
    cStack stack2(stack);
    stack2.print();

    // Assignment operator.
    cout << "Using assignemnt operator to copy old stack to a new stack: " << endl;
    cStack stackDestination = stack;
    stackDestination.print();
}
