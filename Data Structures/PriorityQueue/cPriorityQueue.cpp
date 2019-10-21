#include "cPriorityQueue.h"
using namespace std;

cPriorityQueue::cPriorityQueue() {}

cPriorityQueue::cPriorityQueue(cNode *&ptr) : cQueue(ptr) {}

cPriorityQueue &cPriorityQueue::addInPriorityQue(cNode *&ptr)
{
    if (!top)
    {
        top = tail = ptr;
        tail->nextNode = ptr = NULL;
    }
    else if (top->getPriority() < ptr->getPriority())
    {
        cStack::push(ptr);
    }
    else if (tail->getPriority() >= ptr->getPriority())
    {
        cQueue::add(ptr);
    }
    else
    {
        cNode *rptr, *bptr;
        bptr = rptr = top;
        while (rptr->getPriority() >= ptr->getPriority())
        {
            bptr = rptr;
            rptr = rptr->nextNode;
        }
        ptr->nextNode = rptr;
        bptr->nextNode = ptr;
        ptr = NULL;
    }
    return *this;
}

cNode *cPriorityQueue::removeFromPriorityQue()
{
    return cQueue::remove();
}

cPriorityQueue cPriorityQueue::operator=(const cPriorityQueue &robj)
{
    ((cQueue *)this)->operator=((cQueue &)robj);
    return *this;
}

cPriorityQueue::cPriorityQueue(const cPriorityQueue &src) : cQueue((cQueue &)src){};

void cPriorityQueue::print() const
{
    cQueue::print();
}

bool cPriorityQueue::isEmpty() const { return cStack::isEmpty(); }

bool cPriorityQueue::isNotEmpty() const { return cStack::isNotEmpty(); }

cPriorityQueue::~cPriorityQueue()
{
    cNode *ptr = top;

    tail = NULL; // Tail is going to NULL and we can make remaining code.

    while (ptr)
    {
        ptr = ptr->nextNode;
        delete top;
        top = ptr; // In last loop Top will become Null.
    }
}
