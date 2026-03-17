#include <iostream>
using namespace std;
class heap
{
    int *arr = new int[1000];
    int size = 0;

public:
    void insert(int val)
    {
        // step 1 increase size by one
        size += 1;
        // step 2 find insertion index;
        int index = size;
        // step 3 insert value at index
        arr[index] = val;
        // when keep swaping until parent is not big
        while (index > 1)
        {
            // find parent by i/2
            int parent = index / 2;
            // if parent is less the child swap
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                // make index equl to parent
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
            cout << "Empty heap \n";
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i <= size)
        {
            int leftChildIndex = 2 * i;
            int rightChildIndex = 2 * i + 1;
            int largest = i;

            if (leftChildIndex <= size && arr[leftChildIndex] > arr[largest])
            {
                largest = leftChildIndex;
            }

            if (rightChildIndex <= size && arr[rightChildIndex] > arr[largest])
            {
                largest = rightChildIndex;
            }

            if (largest != i)
            {
                swap(arr[i], arr[largest]);
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
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
        /* code */
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(53);
    h.insert(54);
    h.insert(55);
    h.insert(52);
    h.insert(70);
    h.printHeap();
    h.deleteRoot();
    h.printHeap();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
        if (i == n)
        {
            cout << endl;
        }
    }
    heapSort(arr,n);
      for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
        if (i == n)
        {
            cout << endl;
        }
    }

    return 0;
}