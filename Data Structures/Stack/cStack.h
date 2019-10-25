/**
 * cStack class header
 */

#pragma once
#include <iostream>
#include "cNode.h"
using namespace std;

class cStack
{
    cNode *top;
    int count;

public:
    cStack(); // Default constructor.

    cStack(cNode *&node); // Constructor with parameter.

    cStack &push(cNode *&node); // Push a new node in stack.

    cNode *pop(); // Pop the first node.

    // Constructors for file I/O
    cStack(ifstream &inFile);
    cStack(ofstream &outFile);

    // Member funcitons for file I/O.
    void writeToFile(ofstream &oFile);
    void readFromFile(ifstream &inFile);
    bool postfixPreCondition(string expr) const;			//Precondition to check expression is postfix or not
	bool prefixPreCondition(string expr) const;				//Precondition to check expression is prefix or not
	cStack& postFixEvaluation(string expr);					//For Post fix evaluation
	cStack& preFixEvaluation(string expr);					//For Pre fix evaluation
    void print() const; // Print all nodes.

    cStack(const cStack &src); // Copy constructor for stack.

    cStack &operator=(const cStack &rObj); // Overloading assignment operator.

    ~cStack(); // Destructor.

    // Validation functions.
    bool isEmpty() const;
    bool isNotEmpty() const;
};
