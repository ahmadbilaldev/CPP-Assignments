/**
 * cNode class header
 */

#pragma once
#include <iostream>
using namespace std;

class cNode
{
    int data;
    int priority;

public:
    cNode *nextNode;

    cNode();

    cNode(int d);

    cNode &setData(int input);

    int getData();

    void setPriority(int input);

    int getPriority();

    void printPriority() const;

    void print() const;

    ~cNode();
};
