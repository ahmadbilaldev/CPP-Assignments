/**
 * cNode class
 */

#include <iostream>
#include "cNode.h"
using namespace std;

cNode::cNode() : data(0) {}

cNode::cNode(int d) : data(d) {}

int cNode::getData()
{
    return data;
}

cNode &cNode::setData(int input)
{
    this->data = input;
    return *this;
}

void cNode::print() const
{
    cout << endl
         << data;
}

cNode::~cNode() {}
