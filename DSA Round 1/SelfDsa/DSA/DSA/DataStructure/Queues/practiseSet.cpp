#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int n)
    {
        size = n;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void push(int x)
    {
        if (rear == size)
        {
            cout << "Queue is full \n";
            return;
        }
        arr[rear] = x;
        rear++;
    }
    int pop()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            front++;
            if (front == rear)
            {
                front = rear = 0;
                arr[rear] = -1;
            }
            return ans;
        }
    }
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        return false;
    }
    int frontValue()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }
    void printQue()
    {
        int i = front;
        for (; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool isFull()
    {
        if (rear < size)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
class circleQue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    circleQue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int x)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full";
            return;
        }
        else if (front == -1)
        {
            front=rear=0;
        }
        else if (rear==size-1 && front!=0){
            rear=0;

        }
        else{
            rear++;
        }
        arr[rear]=x;

    }
    int pop()
    {
        if (rear == front)
        {
            cout << "Queue is Empty";
            return;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front==rear)
        {
            front=rear=0;
        }

        else if(front==size-1)
        {
            front=0;
        }
        else
        {

            front++;

        }
        return ans;
    }
    bool isEmpty()
    {   
        if(front==rear)
        {
            return 1;
        }
        return 0;
    }
    bool isFull()
    {
        if(rear+1%size==front)
        {
            return 1;
        }
        return 0;
    }
};
int main()
{
    // Queue q(3);
    // q.push(10);
    // q.push(20);
    // q.push(23);
    // q.printQue();

    // cout<<q.isFull()<<endl;
    // q.printQue();
    return 0;
}