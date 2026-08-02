#include <bits/stdc++.h>
using namespace std;

int main()
{
    // priority_queue<int> pq;
    // pq.push(2);
    // pq.push(4);
    // pq.push(3);
    // pq.push(5);
    // pq.push(6);
    // int size=pq.size();
    // for(int i=0;i<size;i++)
    // {
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    // }
    // cout<<endl;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(11);
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(3);
    minHeap.push(0);
    int size = minHeap.size();
    for (int i = 0; i < size; i++)
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}