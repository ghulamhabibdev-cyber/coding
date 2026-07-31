#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegInt(long long int arr[], long long int n, long long int k)
{
    deque<long long int> dq;
    vector<long long> ans;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    if (dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    
    for (int i = k; i < n; i++)
    {
       if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        if (dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}
int main()
{
    long long int arr[5] = {-8, -2, 3, -6, 10};
    vector<long long int> v = printFirstNegInt(arr, 5, 2);
    for (int i = 0; i < v.size(); i++)
    {
        cout<< v[i] << " ";
    }

    return 0;
}