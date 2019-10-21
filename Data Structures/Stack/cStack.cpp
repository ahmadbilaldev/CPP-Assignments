/**
 * cStack class
 */

#include <iostream>
#include "cStack.h"
using namespace std;

cStack::cStack() : top(NULL) {}

cStack::cStack(cNode *&ptr) : top(ptr)
{
    top->nextNode = NULL;
    ptr = NULL;
}

cStack &cStack::push(cNode *&ptr)
{
    ptr->nextNode = top;
    top = ptr;
    ptr = NULL;
    return *this;
}

cNode *cStack::pop()
{
    cNode *ptr;
    ptr = top;
    top = top->nextNode;
    ptr->nextNode = NULL;
    return ptr;
}

void cStack::print() const
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "Nodes in the Stack are: ";
        cNode *ptr;
        ptr = top;
        while (ptr)
        {
            ptr->print();
            ptr = ptr->nextNode;
        }
        cout << endl;
    }
}

cStack::cStack(const cStack &src)
{
    this->top = src.top;
    if (src.top)
    {
        cNode *sPtr, *dPtr;
        dPtr = top = new cNode(*src.top);
        sPtr = src.top->nextNode;
        while (sPtr)
        {
            dPtr->nextNode = new cNode(*src.top);
            sPtr = sPtr->nextNode;
            dPtr = dPtr->nextNode;
        }
    }
}

cStack &cStack::operator=(const cStack &rObj)
{
    if (this == &rObj)
    {
        return *this;
    }
    if (true)
    {
        cStack temp;
        temp.top = top;
    }
    if (true)
    {
        cStack temp;
        temp = rObj;
        top = temp.top;
        temp.top = NULL;
        return *this;
    }
}

cStack::~cStack()
{
    cNode *ptr = top;
    while (ptr)
    {
        ptr = ptr->nextNode;
        delete top;
        top = ptr;
    }
}

bool cStack::isNotEmpty() const
{
    if (top != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool cStack::isEmpty() const
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
