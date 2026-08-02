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
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Empty   :\n";
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
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
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heafipy(arr, n, largest);
    }
}
void minHeafipy(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        minHeafipy(arr, n, smallest);
    }
}
vector<int> buildHeap(vector<int> &v)
{
    int n = v.size();
    for (int i = n / 2; i >= 0; i--)
    {
        minHeafipy(v, n, i);
    }
    return v;
}
void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size - 1], arr[0]);
        size--;
        heafipy(arr, size, 0);
        /* code */
    }
}
// find kth smallest element of array or heap
int KthSmallest(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
// check wheter given BT is heap or not
// i solve this question in tree section

// merge two max heap
void heafipy2(vector<int> &arr, int n, int i)
{
    int largest = i;
    // int left = 2 * i;
    // int right = 2 * i + 1;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heafipy2(arr, n, largest);
    }
}
vector<int> mergeTwoHeap(vector<int> heap1, vector<int> heap2)
{
    vector<int> ans;
    for (auto i : heap1)
    {
        ans.push_back(i);
    }
    for (auto i : heap2)
    {
        ans.push_back(i);
    }
    int n = ans.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heafipy2(ans, n, i);
    }
    return ans;
}
// minimu cost or ropes
long long minCoost(long long arr[], long long n)
{
    // create min heap
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    // vector<long long> ans;
    long long cost = 0;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}
// kth largest  sum of a  array subarray
int getKthLargestSum(vector<int> &v, int k)
{
    vector<int> sumVec;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += v[j];
            sumVec.push_back(sum);
        }
    }
    sort(sumVec.begin(), sumVec.end());
    return sumVec[sumVec.size() - k];
}
// aproch two
int kthLargetsum(vector<int> v, int k)
{
    priority_queue<int, vector<int>, greater<int>> mini;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += v[j];
            if (mini.size() < k)
            {
                mini.push(sum);
            }
            else
            {
                if (sum > mini.top())
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}
// merge k sorted array
class node
{
public:
    int data;
    int i;
    int j;
    node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};
vector<int> mergeKsortedArray(vector<vector<int>> arr, int k)
{
    priority_queue<node *, vector<node *>, compare> minHeap;
    for (int i = 0; i < k; i++)
    {
        node *temp = new node(arr[i][0], i, 0);
        minHeap.push(temp);
    }
    vector<int> ans;
    while (minHeap.size() > 0)
    {
        node *temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();
        int i = temp->i;
        int j = temp->j;
        if (j + 1 < arr[i].size())
        {
            node *next = new node(arr[i][j + 1], i, j + 1);
            minHeap.push(next);
        }

        /* code */
    }
    return ans;
}
// merge k soted link list

// smallest range from k sortlest lsit
class node2
{
public:
    int data;
    int row;
    int col;
    node2(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare2
{
public:
    bool operator()(node2 *a, node2 *b)
    {
        return a->data > b->data;
    }
};
// int kSorted(vector<vector<int>> &a, int k, int n)
// {
//     int mini = INT_MAX;
//     int maxi = INT_MIN;
//     priority_queue<node2*, vector<node2*>, compare2> minHeap;
//     for (int i = 0; i < k; i++)
//     {
//         int element = a[i][0];
//         maxi = max(maxi, element);
//         mini = min(mini, element);
//         minHeap.push(new node2(element,i,0));
//     }
//     int start = mini;
//     int end = maxi;
//     while (!minHeap.empty())
//     {
//         node2 *temp = minHeap.top();
//         minHeap.pop();
//         mini = temp->data;
//         if (maxi - mini < end - start)
//         {
//             start = mini;
//             end = maxi;
//         }
//         if (temp->col+1 < n)
//         {
//             maxi = max(maxi, a[temp->row][temp->col + 1]);
//             minHeap.push(new node2(a[temp ->row][temp->col + 1], temp->row, temp->col + 1));
//         }
//         else
//         {
//             break;
//         }
//     }
//     return (end-start+1);
// }

pair<int, int> kSorted(vector<vector<int>> &a, int k, int n)
{
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node2*, vector<node2*>, compare2> minHeap;

    // Step 1: Push first element of each list
    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        minHeap.push(new node2(element, i, 0));
    }

    int start = mini, end = maxi;

    // Step 2: Process heap
    while (!minHeap.empty())
    {
        node2* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        // Update best range
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // Push next element from same row
        if (temp->col + 1 < n)
        {
            int nextVal = a[temp->row][temp->col + 1];
            maxi = max(maxi, nextVal);
            minHeap.push(new node2(nextVal, temp->row, temp->col + 1));
        }
        else
        {
            break; // stop when one list ends
        }
    }

    return {start, end}; // return the actual range
}

int main()
{

    // vector<int> v1 = {100, 105, 50, 51};
    // vector<int> v2 = {48, 32, 43, 43, 90};

    // int arr[10] = {50, 51, 41, 30, 32, 15, 10, 16, 60, 70};
    // int n = 10;
    // cout << "kth samllest element :  " << KthSmallest(arr, 10, 3);
    // vector<int> ans=mergeTwoHeap(v1,v2);
    // for(auto i: ans)
    // {
    //     cout<<i<<" ";
    // }
    // long long arr[4] = {4,3,2,6};
    // long long n = minCoost(arr,4);
    // cout<<"Total min cost :   " <<n<<endl;
    // cout << endl;
    // vector<int> v1 = {1, 3, 5, 3};
    // cout << "kth smu : " << getKthLargestSum(v1, 4) << endl;
    // cout << "kth largest sum   :  " << kthLargetsum(v1, 4) << endl;

    vector<int> v1 = {1, 10, 11};
    vector<int> v2 = {2, 3, 20};
    vector<int> v3 = {5, 6, 12};
    // vector<int> v4 = {10, 3, 5, 6};
    vector<vector<int>> mg;
    mg.push_back(v1);
    mg.push_back(v2);
    mg.push_back(v3);
    // mg.push_back(v4);
    // vector<int> ans = mergeKsortedArray(mg, 4);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    pair<int, int> ans =  kSorted(mg, mg.size(), 3);;
    cout << "Kth smallest range :    " << ans.first << endl;
    cout << "Kth smallest range :    " << ans.second << endl;

    return 0;
}