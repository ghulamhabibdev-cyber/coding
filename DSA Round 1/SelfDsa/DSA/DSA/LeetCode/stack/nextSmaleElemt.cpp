#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerelement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    // 2,1,4,3
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}
int main()
{
    vector<int> num;
    num.push_back(2);
    num.push_back(1);
    num.push_back(4);
    num.push_back(3);
    vector<int> ans;
    ans = nextSmallerelement(num, 4);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}