/**
 * cQueue class
 */

#include <iostream>
#include "cQueue.h"

using namespace std;

cQueue::cQueue() : tail(NULL) {} // Default constructor.

cQueue::cQueue(cNode *&ptr) : cStack(ptr) { tail = top; } // Constructor with parameter.

cQueue &cQueue::add(cNode *&ptr) // Adds a new node at top of the Queue.
{
    if (tail)
    {
        tail->nextNode = ptr;
        tail = tail->nextNode;
    }
    else
        tail = top = ptr;

    tail->nextNode = ptr = NULL;
    return *this;
}

cNode *cQueue::remove() // Removes last node from the Queue.
{
    if (!(top->nextNode))
        tail = NULL;

    return cStack::pop();
}

cQueue::cQueue(const cQueue &src) // Self defined copy constructor.
{
    this->top = src.top;
    this->tail = src.tail;
    if (src.top)
    {
        cNode *sptr, *dptr;
        dptr = top = new cNode(*src.top);
        sptr = src.top->nextNode;

        while (sptr)
        {
            dptr->nextNode = new cNode(*sptr);
            dptr = dptr->nextNode;
            sptr = sptr->nextNode;
        }
        tail = dptr;
    }
}

cQueue &cQueue::operator=(const cQueue &obj) // Overloads assingment operator
{
    if (this == &obj)
    {
        return *this;
    }

    if (true)
    {
        cQueue temp;
        temp.top = top;
        temp.tail = tail;
    }
    if (true)
    {
        cQueue temp;
        temp = obj;
        top = temp.top;
        tail = temp.tail;
        temp.top = NULL;
        temp.tail = NULL;
        return *this;
    }
}

void cQueue::print() const // Prints all nodes in the Queue.
{
    cStack::print();
}

cQueue::~cQueue() // Destructor.
{
    cNode *ptr = top;

    tail = NULL;

    while (ptr)
    {
        ptr = ptr->nextNode;
        delete top;
        top = ptr;
    }
}

// Validation functions.

bool cQueue::isEmpty() const { return cStack::isEmpty(); }

bool cQueue::isNotEmpty() const { return cStack::isNotEmpty(); }
