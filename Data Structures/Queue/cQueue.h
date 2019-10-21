/**
 * cQueue class header
 */

#pragma once
#include <iostream>
#include "cNode.h"
#include "cStack.h"
using namespace std;

class cQueue : protected cStack
{
protected:
    cNode *tail;

public:
    cQueue();

    cQueue(cNode *&Ptr);

    cQueue(const cQueue &Source);

    cQueue &operator=(const cQueue &Source);

    cQueue &add(cNode *&Ptr);

    void print() const;

    ~cQueue();

    cNode *remove();

    bool isEmpty() const;

    bool isNotEmpty() const;
};
