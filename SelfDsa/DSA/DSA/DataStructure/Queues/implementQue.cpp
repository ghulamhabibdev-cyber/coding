#include <bits/stdc++.h>
using namespace std;
class Quesue
{

    int *arr;
    int frontIndex;
    int rear;
    int size;

public:
    Quesue()
    {
        size = 1000;
        arr = new int[size];
        frontIndex = 0;
        rear = 0;
    }
    void enque(int n)
    {
        if (rear == size)
        {
            cout << "Queue is full  \n";
            return;
        }
        arr[rear] = n;
        rear++;
    }
    int deque()
    {
        if (frontIndex == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[frontIndex];
            frontIndex++;
            if (frontIndex == rear)
            {
                frontIndex = 0;
                rear = 0;
            }
            return ans;
        }
    }
    int front()
    {
        if (frontIndex == rear)
        {
            return -1;
        }
        return arr[frontIndex];
    }
    bool isEmpty()
    {
        if (frontIndex == rear)
        {
            return 1;
        }
        return 0;
    }
};
int main()
{
    Quesue q;
    q.enque(3);
    q.enque(23);
    q.enque(23);

    cout << q.front();
    return 0;
}