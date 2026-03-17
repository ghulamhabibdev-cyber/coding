#include <iostream>
using namespace std;

class maxHeap
{
    int *heap;
    int size;

public:
    maxHeap(int size)
    {
        heap = new int[size];
        this->size = 0;
    }
    void insertValue(int value)
    {
        size += 1;
        int index = size;
        heap[index] = value;
        while (index > 1)
        {
            int parent = index / 2;
            if (heap[parent] < heap[index])
            {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "Heap is Empty \n";
            return;
        }
        heap[1] = heap[size];
        size--;
        int i = 1;
        while (i <= size)
        {
            int largest = i;
            int left = 2 * i;
            int right = 2 * i + 1;
            if (left <= size && heap[largest] < heap[left])
            {
                largest = left;
            }
            if (right <= size && heap[largest] < heap[right])
            {
                largest = right;
            }
            if (largest != i)
            {
                swap(heap[largest], heap[i]);
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
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};
void heapify(int arr[], int n, int i)
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
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}
class minHeap
{
    int *arr;
    int size;

public:
    minHeap(int n)
    {
        arr = new int[n];
        size = 0;
    }
    void insert(int val)
    {
        size += 1;
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
                break;
            }
        }
    }
    void printMinHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
    void deleteMinHeap()
    {
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i <= size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = i;
            if (left <= size && arr[smallest] > arr[left])
            {
                smallest = left;
            }
            if (right <= right && arr[smallest] > arr[right])
            {
                smallest = right;
            }
            if (smallest != i)
            {
                swap(arr[smallest], arr[i]);
                i = smallest;
            }
            else
            {
                break;
            }
        }
    }
};
int main()
{
    // maxHeap h(1000);
    // h.insertValue(10);
    // h.insertValue(20);
    // h.insertValue(100);
    // h.insertValue(80);
    // h.insertValue(49);
    // h.insertValue(89);

    // h.printHeap();
    // h.deleteRoot();
    // h.printHeap();
    // h.deleteRoot();
    // h.printHeap();
    // int arr[19] = {323, 4, 434, 543, 4534, 34, 23, 434, 54, 3432, 3244, 343, 3, 42, 35, 545, 34, 34353, 343};
    // int n = 18;
    // for (int i = n / 2; i > 0; i--)
    // {
    //     heapify(arr, n, i);
    // };
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // heapSort(arr, n);
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    minHeap minH(100);
    minH.insert(400);
    minH.insert(40);
    minH.insert(500);
    minH.insert(300);
    minH.insert(560);
    minH.insert(1);
    minH.insert(0);
    minH.printMinHeap();
    minH.deleteMinHeap();
    minH.printMinHeap();
    minH.deleteMinHeap();
    minH.printMinHeap();

    return 0;
}