#include <iostream>
#include "12.h"
using namespace std;
void findQueueSum(linkyQueue qt)
{
    int sum = 0;
    while (!qt.isEmpty())
    {
        sum += qt.queueFront();
        qt.dequeue();
    }
    cout << "Quequ sum : " << sum << endl;
}
void findQueueAverage(linkyQueue qt)
{

    double average = 0;
    int sum = 0;
    int size = qt.size();
    while (!qt.isEmpty())
    {
        sum += qt.queueFront();
        qt.dequeue();
    }
    average = sum / size;
    cout << "Queue Average : " << average << endl;
}
int main()
{
    cout << "=========================== Sum of Queue==============================\n";

    linkyQueue qt;
    qt.enqueue(10);
    qt.enqueue(20);
    qt.enqueue(30);
    qt.enqueue(40);
    qt.enqueue(50);
    findQueueSum(qt);
    cout << "===============================Average of Queue =========================== \n";
    linkyQueue qt2;
    qt2.enqueue(10);
    qt2.enqueue(20);
    qt2.enqueue(30);
    qt2.enqueue(40);
    qt2.enqueue(50);
    findQueueAverage(qt2);
    return 0;
}
