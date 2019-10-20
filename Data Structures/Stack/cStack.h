#include <iostream>
#include "cNode.h"
using namespace std;

class cStack
{
    cNode *top;

public:
    cStack();

    cStack(cNode *&node);

    cStack &push(cNode *&node);

    cStack *pop();

    void print() const;

    cStack &operator=(const cStack &rObj);

    ~cStack();
};
