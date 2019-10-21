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

public:
    cStack(); // Default constructor.

    cStack(cNode *&node); // Constructor with parameter.

    cStack &push(cNode *&node); // Push a new node in stack.

    cNode *pop(); // Pop the first node.

    void print() const; // Print all nodes.

    cStack(const cStack &src); // Copy constructor for stack.

    cStack &operator=(const cStack &rObj); // Overloading assignment operator.

    ~cStack(); // Destructor.

    // Validation functions.
    bool isEmpty() const;
    bool isNotEmpty() const;
};
