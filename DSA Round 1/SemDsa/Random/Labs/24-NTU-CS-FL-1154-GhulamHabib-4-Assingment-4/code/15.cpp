#include <iostream>
using namespace std;
class queue
{
private:
    int front;
    int back;
    int *arr;
    int maxSize;
    int count;

public:
    queue(int size);
    void enqueue(int);
    void dequeue();
    int queueFront();
    int queueBack();
    bool isEmpty();
    bool isFull();
    void print();
    int size();
    ~queue();
};
queue::~queue()
{
    delete[] arr;
}
int queue::size()
{
    return count;
}
void queue::print()
{
    if (!isEmpty())
    {
        for (int i = front; i <= back; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Empty List \n";
    }
}
int queue::queueBack()
{
    if (!isEmpty())
    {
        return arr[back];
    }
    return -1;
}
int queue::queueFront()
{
    if (!isEmpty())
    {
        return arr[front];
    }
    return -1;
}
void queue::enqueue(int data)
{
    if (!isFull())
    {
        back = (back + 1) % maxSize;
        count++;
        arr[back] = data;
    }
    else
    {
        cout << "Queue is Full \n";
    }
}
void queue::dequeue()
{
    if (!isEmpty())
    {
        count--;
        front = (front + 1) % maxSize;
    }
    else
    {
        cout << "Empty List \n";
    }
}
bool queue::isEmpty()
{
    return count == 0;
}
bool queue::isFull()
{
    return count == maxSize;
}
queue::queue(int size)
{
    if (size <= 0)
    {
        maxSize = 100;
    }
    maxSize = size;
    arr = new int[maxSize];
    front = 0;
    back = maxSize - 1;
    count = 0;
}

int main()
{
    queue qt(10);
    qt.enqueue(10);
    qt.enqueue(20);
    cout << qt.isFull() << endl;
    qt.print();
    qt.dequeue();

    qt.dequeue();
    qt.dequeue();
    qt.print();

    cout << qt.isEmpty() << endl;

    return 0;
}
