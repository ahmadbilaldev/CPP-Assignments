/**
 * cNode class header
 */

#pragma once
#include <iostream>
using namespace std;

class cNode
{
    int data;

public:
    cNode *nextNode;

    cNode();

    cNode(int d);

    cNode &setData(int input);

    int getData();

    void print() const;

    ~cNode();
};
