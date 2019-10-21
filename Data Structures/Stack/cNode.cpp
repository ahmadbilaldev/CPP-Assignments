/**
 * cNode class
 */

#include <iostream>
#include "cNode.h"
#include <fstream>
using namespace std;

// Default constructor.
cNode::cNode() : data(0) {}

// Constructor with parameters.
cNode::cNode(int d) : data(d) {}

// Getter function.
int cNode::getData()
{
    return data;
}

// Setter function.
cNode &cNode::setData(int input)
{
    this->data = input;
    return *this;
}

// File I/O funcitons.
void cNode::readNodeFromFile(ifstream &inFile) { inFile.read((char *)this, sizeof(this)); }

void cNode::writeNodeToFile(ofstream &oFile) { oFile.write((char *)this, sizeof(this)); }

cNode::cNode(ifstream &inFile) { inFile.read((char *)this, sizeof(this)); }

cNode::cNode(ofstream &oFile)
{
    oFile.write((char *)this, sizeof(this));
}

// Prints all nodes in the stack.
void cNode::print() const
{
    cout << endl
         << data;
}

// Destructor.
cNode::~cNode() {}
