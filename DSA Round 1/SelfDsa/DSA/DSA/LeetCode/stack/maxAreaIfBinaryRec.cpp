#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerelement(int *arr, int n)
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
vector<int> prevSmallerElement(int *arr, int n)
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
int longestAreaOfHisRec(int *arr, int n)
{

    vector<int> next(n);
    next = nextSmallerelement(arr, n);

    vector<int> prev(n);
    prev = prevSmallerElement(arr, n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = arr[i];

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
int MaxAreaOfBinaryRectangle(int arr[][4], int n,int m)
{
   
    int area=longestAreaOfHisRec(arr[0],m);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]!=0)
            {
                arr[i][j]=arr[i][j]+arr[i-1][j];
            }
            else{
                arr[i][j]=0;
            }
            int newArea=longestAreaOfHisRec(arr[i],m);
            area=max(area,newArea);
        }

    }
    return area;
}
int main()
{
    int arr[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    } ;
    cout<<MaxAreaOfBinaryRectangle(arr,4,4);

    return 0;
}