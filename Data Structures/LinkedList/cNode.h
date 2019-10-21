#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class cNode
{
    int data;

public:
    cNode *nextNode;
    cNode();
    cNode(int value);
    cNode &setData(int value);
    int getData();
    void print() const;
};
