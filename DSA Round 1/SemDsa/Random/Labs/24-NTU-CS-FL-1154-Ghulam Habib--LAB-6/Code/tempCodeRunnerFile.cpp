#include <iostream>
#include "queue.h"
using namespace std;
int main()
{
    queque qt;
    qt.enqueue(10);
    qt.enqueue(20);
    qt.enqueue(30);
    qt.enqueue(40);
    qt.printQueue();
    qt.dequeue();
    qt.printQueue();
    qt.dequeue();
    qt.printQueue();

    return 0;
}
