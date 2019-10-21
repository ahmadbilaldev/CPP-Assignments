#include "cQueue.h"
#include <iostream>

using namespace std;

class cPriorityQueue : protected cQueue
{
public:
    cPriorityQueue();

    cPriorityQueue(cNode *&ptr);

    cPriorityQueue &addInPriorityQue(cNode *&ptr);

    cNode *removeFromPriorityQue();

    cPriorityQueue(const cPriorityQueue &src);

    cPriorityQueue operator=(const cPriorityQueue &robj);

    void print() const;

    ~cPriorityQueue();

    bool isEmpty() const;

    bool isNotEmpty() const;
};
