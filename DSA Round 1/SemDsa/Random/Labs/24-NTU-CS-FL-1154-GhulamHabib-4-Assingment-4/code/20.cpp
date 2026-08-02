#include <iostream>
using namespace std;
class doubleQueue
{
    int front1, back1;
    int front2, back2;
    int *arr;
    int maxSize;

public:
    doubleQueue(int);
    void enqueue1(int);
    void enqueue2(int);
    void dequeue1();
    void dequeue2();

    int queueFront1();
    int queueBack1();
    int queueFront2();
    int queueBack2();
    void print1();
    void print2();
};
void doubleQueue::print1()
{
    if (back1 == -1)
    {
        cout << "Empty q 1\n";
        return;
    }

    for (int i = front1; i <= back1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void doubleQueue::print2()
{
    if (back2 == maxSize)
    {
        cout << "queue 2 is empty \n";
        return;
    }

    for (int i = front2; i >= back2; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int doubleQueue::queueFront1()
{
    if (front1 != -1 || front1 > back1)
    {
        return arr[front1];
    }
    return -1;
}
int doubleQueue::queueFront2()
{
    if (front1 != maxSize || front2 < back2)
    {
        return arr[front2];
    }
    return -1;
}
int doubleQueue::queueBack1()
{
    if (back1 != -1 || back1 + 1 < back2)
    {
        return arr[back1];
    }
    return -1;
}
int doubleQueue::queueBack2()
{
    if (back2 != maxSize || back2 > back1 + 1)
    {
        return arr[back1];
    }
    return -1;
}
doubleQueue::doubleQueue(int size)
{
    if (size <= 0)
    {
        maxSize = 100;
    }
    else
    {
        maxSize = size;
    }
    arr = new int[maxSize];
    back1 = front1 = -1;
    back2 = front2 = maxSize;
}
void doubleQueue::enqueue1(int data)
{
    if (back1 + 1 == back2)
    {
        cout << "Queue overflow\n";
        return;
    }
    if (front1 == -1)
    {
        front1 = 0;
    }
    back1++;
    arr[back1] = data;
}
void doubleQueue::dequeue1()
{
    if (front1 == -1 || front1 > back1)
    {
        cout << "Overflow queue 1 \n";
        return;
    }
    front1++;
    if (front1 > back1)
    {
        front1 = back1 = -1;
    }
}
void doubleQueue::enqueue2(int data)
{
    if (back1 + 1 == back2)
    {
        cout << "Queue 2 Overflow!\n";
        return;
    }
    if (front2 == maxSize)
    {
        front2 = maxSize - 1;
    }
    back2--;
    arr[back2] = data;
}
void doubleQueue::dequeue2()
{
    if (front2 == maxSize || front2 < back2)
    {
        cout << "Overflow\n";
    }
    front2--;
    if (front2 < back2)
        front2 = back2 = maxSize;
}
int main()
{
    doubleQueue q(10);
    q.enqueue1(4);
    q.enqueue1(5);
    q.enqueue1(6);
    q.enqueue1(7);
    q.print1();
    q.dequeue1();
    q.dequeue1();
    q.print1();
    q.enqueue2(100);
    q.enqueue2(150);
    q.enqueue2(250);
    q.enqueue2(350);
    q.print2();
    q.dequeue2();
    q.dequeue2();
    q.print2();

    return 0;
}
