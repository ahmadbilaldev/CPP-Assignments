/**
 * cStack class
 */

#include <iostream>
#include "cStack.h"
#include <fstream>
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

// Constructor. Takes nodes as input from file.
cStack::cStack(ifstream &inFile) : top(NULL), count(0)
{
    int size;
    inFile.read((char *)&size, sizeof(size));
    if (size > 0)
    {
        cNode *rptr;
        rptr = top = new cNode(inFile);
        count = size;
        for (int i = 1; i < count; ++i)
        {
            rptr->nextNode = new cNode(inFile);
            rptr = rptr->nextNode;
        }
        rptr->nextNode = NULL;
        rptr = NULL;
    }
}

// Constructor. Outputs nodes to file.
cStack::cStack(ofstream &outFile)
{
    outFile.write((char *)&count, sizeof(count));
    if (count > 0)
    {
        cNode *ptr = top;
        ptr = new cNode(outFile);
        for (int i = 1; i < count; i++)
        {
            ptr->nextNode = new cNode(outFile);
            ptr = ptr->nextNode;
        }
    }
}

// Writes nodes to file.
void cStack::writeToFile(ofstream &oFile)
{
    if (!(oFile.is_open()))
    {
        cout << "File is not opened !" << endl;
    }
    else
    {
        oFile.write((char *)&this->count, sizeof(count));

        if (count > 0)
        {
            cNode *rptr = top;
            for (int i = 0; i < count; ++i)
            {
                rptr->writeNodeToFile(oFile);
                rptr = rptr->nextNode;
            }
        }
    }
}

// Takes nodes as input from file.
void cStack::readFromFile(ifstream &inFile)
{

    if (true)
    {
        cStack temp;
        temp.top = this->top;
    }

    inFile.read((char *)&count, sizeof(count));
    cout << "count = " << count << endl;

    if (count > 0)
    {
        cNode *temp;
        temp = top = new cNode(inFile);

        for (int i = 1; i < count; ++i)
        {
            temp->nextNode = new cNode(inFile);
            temp = temp->nextNode;
        }
        temp->nextNode = NULL;
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
