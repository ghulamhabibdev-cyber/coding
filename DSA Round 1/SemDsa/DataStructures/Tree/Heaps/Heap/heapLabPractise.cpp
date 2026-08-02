#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class maxHeap
{

public:
    int size;
    int arr[10000];
    maxHeap()
    {
        size = 0;
    }

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deleteItem()
    {
        if (size == 0)
        {
            cout << "Heap is Empty \n";
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i <= size)
        {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;
            int largest = i;
            if (leftChild <= size && arr[largest] < arr[leftChild])
            {
                largest = leftChild;
            }
            if (rightChild <= size && arr[largest] < arr[rightChild])
            {
                largest = rightChild;
            }
            if (largest != i)
            {
                swap(arr[largest], arr[i]);
                i = largest;
            }
            else
            {
                return;
            }
        }
    }
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
class minHeap
{
public:
    int size;
    int arr[1000];
    minHeap()
    {
        size = 0;
    }
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deleteItem()
    {
        if (size == 0)
        {
            cout << "Empty Heap \n";
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i <= size)
        {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;
            int smallest = i;
            if (leftChild <= size && arr[smallest] > arr[leftChild])
            {
                smallest = leftChild;
            }
            if (rightChild <= size && arr[smallest] > arr[rightChild])
            {
                smallest = rightChild;
            }
            if (smallest != i)
            {
                swap(arr[smallest], arr[i]);
                i = smallest;
            }
            else
            {
                return;
            }
        }
    }
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
void heafipy(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heafipy(arr, n, largest);
    }
}
void heapSort(int arr[],int n,int i)
{
    int size=n;
    while(size>1)
    {
        swap(arr[size],arr[1]);
        size--;
        heafipy(arr,size,1);

    }
}
int main()
{
    maxHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(100);
    h.insert(80);
    h.insert(49);
    h.insert(89);

    h.printHeap();
    h.deleteItem();
    h.printHeap();
    h.deleteItem();
    h.printHeap();

    cout << "==========================MIN HEAP =========================================\n";
    minHeap mh;
    mh.insert(100);
    mh.insert(120);
    mh.insert(1);
    mh.insert(2);
    mh.insert(3);
    mh.insert(4);
    mh.insert(5);
    mh.insert(50);
    mh.printHeap();
    mh.deleteItem();
    mh.printHeap();
    mh.deleteItem();
    mh.printHeap();
    int arr[8] = {-1, 54, 655, 67, 7665, 545, 45, 43};
    int n = 7;
    for (int i = n / 2; i > 0; i--)
    {
        heafipy(arr, 7, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    heapSort(arr,n,1);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}