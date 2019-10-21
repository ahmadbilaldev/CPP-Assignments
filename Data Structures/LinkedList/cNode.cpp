#include "cNode.h"
#include <iostream>
#include <fstream>
using namespace std;

cNode::cNode() : nextNode(0), data(0) {}

cNode::cNode(int value) : data(value) {}

cNode &cNode::setData(int value)
{
    this->data = value;
    return *this;
}

int cNode::getData()
{
    return data;
}

void cNode::print() const
{
    cout << endl
         << data;
}
