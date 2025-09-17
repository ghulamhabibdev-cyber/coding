#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerelement(vector<int> arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    // 2,1,4,3
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int longestAreaOfHisRec(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerelement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}
int MaxAreaOfBinaryRectangle(int *arr,int n)
{
    
}
int main()
{
    vector<int> h;
    h.push_back(2);
    h.push_back(1);
    h.push_back(5);
    h.push_back(6);
    h.push_back(2);
    h.push_back(3);
    cout<<longestAreaOfHisRec(h);

    return 0;
}