#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int stepToMakeGoodArray(vector<int> arr)
{
    stack<long long> st;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        long long curr = arr[i]%2;
        while (!st.empty() && (st.top()  == curr ))
        {
            st.pop();
            curr=curr*curr;
            count++;
        }
        st.push(curr);
    }
    return count;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << stepToMakeGoodArray(arr) << endl;
    }

    return 0;
}