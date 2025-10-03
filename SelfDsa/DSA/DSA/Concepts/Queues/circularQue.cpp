#include <bits/stdc++.h>
using namespace std;
class circularQue
{
    int *arr;
    int size;
    int rear;
    int front;

public:
    circularQue()
    {
        size = 10000;
        arr = new int[size];
        front = -1;
        rear = 1;
    }
    bool enQue(int n)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Que is full \n";
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear = size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = n;
        return true;
    }
    int deque()
    {
        if (front == -1)
        {
            cout << "Empty Queue\n";
            return -1;

        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear)
        {
            front=rear=-1;
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

};
int main()
{

    circularQue q;
    q.enQue(1);
    return 0;
}