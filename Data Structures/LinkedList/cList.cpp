#include "cList.h"
#include <iostream>
#include <fstream>
using namespace std;

// Default constructor.
cList::cList() : headNode(NULL), count(0) {}

// Constructor with parameter.
cList::cList(cNode *&ptr)
{
    headNode = ptr;
    headNode->nextNode = NULL;
    count = 1;
}

// Inserts a node in the list.
cList &cList::insert(cNode *&ptr)
{
    ptr->nextNode = headNode;
    headNode = ptr;
    ptr = NULL;
    ++count;
    return *this;
}

// Inserts a node at the specified index
cList &cList::insertAt(int index, cNode *&ptr)
{
    if (index < 0)
        return insert(ptr);

    if (index >= count)
        index = count;

    cNode *rPtr = headNode;
    for (int i = 0; i < index; ++i)
        rPtr = rPtr->nextNode;

    ptr->nextNode = rPtr->nextNode;
    rPtr->nextNode = ptr;
    ptr = NULL;
    ++count;
    return *this;
}

// Deletes a node from linked list.
cNode *cList::remove()
{
    cNode *temp;
    temp = headNode;
    headNode = headNode->nextNode;
    temp->nextNode = NULL;
    --count;
    return temp;
}

// Deletes node at a specific index.
cNode *cList::removeAt(int index)
{
    if (index <= 0)
    {
        return remove();
    }
    if (index >= count)
    {
        index = count;
    }
    cNode *rptr = headNode;
    for (int i = 1; i < index - 1; ++i)
        rptr = rptr->nextNode;
    cNode *ptr = rptr->nextNode;
    rptr->nextNode = ptr->nextNode;
    --count;
    return ptr;
}

// Cancatenating one list with another list.
cList &cList::operator+(const cList &robj)
{
    if (robj.count == 0)
        return *this;
    cList rCopy = robj;
    if (!headNode)
        headNode = rCopy.headNode;
    else
    {
        cNode *ptr = headNode;

        for (int i = 0; i < count; ++i)
            ptr = ptr->nextNode;
        ptr->nextNode = rCopy.headNode;
        count += rCopy.count;
    }
    rCopy.headNode = NULL;
    return *this;
}

// Deletes node.
void deleteNode(cNode *givenNode)
{
    if (givenNode)
    {
        deleteNode(givenNode->nextNode);
        delete givenNode;
    }
}

// Prints all nodes in the linked list.
void cList::print() const
{
    if (count == 0)
    {
        cout << "Linked List is empty" << endl;
    }
    else
    {
        cNode *temp = headNode;
        cout << "Nodes in the Linked List are: ";
        for (int i = 0; i < count; ++i)
        {
            temp->print();
            temp = temp->nextNode;
        }
    }
}

// Copy constructor.
cList::cList(const cList &src) : headNode(src.headNode), count(src.count)
{
    if (count > 0)
    {
        cNode *sptr, *dptr;
        dptr = headNode = new cNode(*src.headNode);
        sptr = src.headNode->nextNode;
        while (sptr)
        {
            dptr->nextNode = new cNode(*sptr);
            sptr = sptr->nextNode;
            dptr = dptr->nextNode;
        }
        dptr->nextNode = NULL;
    }
}

// Overloading assignment operator.
cList &cList::operator=(const cList &src)
{
    if (this == &src)
        return *this;

    if (true)
    {
        cList temp;
        temp.headNode = this->headNode;
    }
    if (true)
    {
        cList temp;
        temp = src;
        this->headNode = temp.headNode;
        temp.headNode = NULL;
    }
    return *this;
}

// Destructor
cList::~cList()
{
    deleteNode(headNode);
    {
        void deleteNode(cNode * ptr);
    }
}

// Validation functions.
bool cList::isEmpty()
{
    if (headNode == NULL)
        return true;
    else
        return false;
}
bool cList::isNotEmpty()
{
    if (headNode != NULL)
        return true;
    else
        return false;
}
