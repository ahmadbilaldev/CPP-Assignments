#include <iostream>
using namespace std;

class cNode
{
    int data;

public:
    cNode();

    cNode(int d);

    cNode &setData(int data);

    int getData();

    void print() const;

    ~cNode();
};
