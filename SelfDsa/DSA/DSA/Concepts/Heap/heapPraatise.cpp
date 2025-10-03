#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int arr[100];
    int size = 0;
    void insert(int val)
    {
        size = size + 1;
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
            /* code */
        }
    }
    void print()
    {
        if (size == 0)
        {
            return;
        }
        for (int i = 1; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deleteFromHeap()
    {
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int left = 2 * i;
            int right = 2 + i + 1;
            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            if (right < size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }

            /* code */
        }
    }
};
void heafipy(int arr[], int n, int i)
{
    int largest = i;
    // int left = 2 * i;
    // int right = 2 * i + 1;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left<n&& arr[largest]<arr[left])
    {
        largest=left;
    }
     if(right<n&& arr[largest]<arr[right])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heafipy(arr,n,largest);
    }
}
void minHeafipy(vector<int>&arr,int n,int i)
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[smallest]>arr[left])
    {
        smallest=left;

    }
    if(right<n&&arr[smallest]>arr[right])
    {
        smallest=right;
        
    }
    if(smallest!=i)
    {
        swap(arr[smallest],arr[i]);
        minHeafipy(arr,n,smallest);
    }
}
vector<int> buildHeap(vector<int> &v)
{
    int n=v.size();
    for(int i=n/2;i>=0;i--)
    {
        minHeafipy(v,n,i);
    }
    return v;
}
void heapSort(int arr[], int n)
{
    int size=n;
    while (size>1)
    {
         swap(arr[size - 1], arr[0]);
         size--;
         heafipy(arr,size,0);
        /* code */
    }
    
}
int main()
{
    // heap h;
    // h.insert(20);
    // h.insert(50);
    // h.insert(20);
    // h.insert(56);
    // h.insert(43);
    // h.insert(44);
    // h.print();
    // h.deleteFromHeap();
    // h.print();
    // int arr[10] = {50, 51, 41, 30, 32, 15, 10, 16, 60, 70};
    // int n = 10;
    // for(int i=n/2;i>=0;i--)
    // {
    //     heafipy(arr,n,i);
    // }
    // for(int x:arr)
    // {
    //     cout<<x<<" ";
    // }
    // vector<int> v = {50, 51, 41, 30, 32, 15, 10, 16, 60, 70};
    // v=buildHeap(v);
    // for(int x:v)
    // {
    //     cout<<x<< " ";
    // }
    int arr[10] = {50, 51, 41, 30, 32, 15, 10, 16, 60, 70};
     int n = 10;
    for(int i=n/2;i>=0;i--)
    {
        heafipy(arr,n,i);
    }
    for(int x:arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    heapSort(arr,n);
    for(int x:arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}