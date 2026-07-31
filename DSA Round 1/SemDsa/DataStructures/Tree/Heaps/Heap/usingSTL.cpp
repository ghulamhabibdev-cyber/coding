#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    // ---------- MAX HEAP ----------
    priority_queue<int> pq;   // default = max heap

    pq.push(50);
    pq.push(20);
    pq.push(70);
    pq.push(40);
    pq.push(60);

    cout << "Max Heap\n";
    cout << "Top element: " << pq.top() << endl;
    cout << "Size: " << pq.size() << endl;
    cout << "Is empty? " << pq.empty() << endl;

    cout << "Elements (popping): ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    cout << "Is empty after popping? " << pq.empty() << endl;

    // ---------- MIN HEAP ----------
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(50);
    minHeap.push(20);
    minHeap.push(70);
    minHeap.push(40);
    minHeap.push(60);

    cout << "\nMin Heap\n";
    cout << "Top element: " << minHeap.top() << endl;
    cout << "Size: " << minHeap.size() << endl;
    cout << "Is empty? " << minHeap.empty() << endl;

    cout << "Elements (popping): ";
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    cout << "Is empty after popping? " << minHeap.empty() << endl;

    return 0;
}
