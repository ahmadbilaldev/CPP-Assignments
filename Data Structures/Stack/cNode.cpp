#include <iostream>
#include cNode.h
using namespace std;

class cNode
{
    int data;

public:
    cNode *nextNode;

    cNode() {}

    cNode(int d) : data(d) {}

    int getData() const
    {
        return data;
    }

    int &setData()
    {
        this->data = data;
    }

    void print()
    {
        cout << endl
             << data;
    }
};
