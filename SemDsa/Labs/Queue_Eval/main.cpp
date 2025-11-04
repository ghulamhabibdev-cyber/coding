#include <iostream>
#include "queue.h"
#include <string>
using namespace std;

int main()
{
    queue qt;
    cout << "=========== Adding Customer==================\n";
    qt.enqueue(101, "Habib", "Deposite");
    qt.enqueue(102, "ALi", "Withdraw");
    qt.enqueue(104, "ahmad", "Balance");
    cout << "============== Displaying ================\n";
    qt.diplayQueue();
    cout << "=========After Servicing one customer =============\n";
    qt.dequeue();
    qt.diplayQueue();
    return 0;
}
