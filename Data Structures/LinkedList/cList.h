#pragma once
#include "cNode.h"
#include <iostream>
#include <fstream>

using namespace std;

class cList
{
    cNode *headNode;

public:
    int count;

    cList();
    cList(cNode *&ptr);
    cList &insert(cNode *&ptr);
    cList &insertAt(int index, cNode *&ptr);
    cNode *remove();
    cNode *removeAt(int index);
    cList &swapNodesAt(int index1, int index2);
    cList &reverse();
    cList &operator+(const cList &robj);
    void print() const;
    cList(const cList &src);
    cList &operator=(const cList &robj);
    ~cList();
    bool isEmpty();
    bool isNotEmpty();
};
