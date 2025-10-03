#include <bits/stdc++.h>
using namespace std;
vector<int> addToArrayForm(vector<int> &num, int k)
{
    int index = num.size() - 1;
    int carry = 0;
    vector<int> res;
    while (index >= 0)
    {
        int digit = k % 10;
        int sum = num[index] + digit + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
        k = k / 10;
        index--;
    }
    if (k > 0)
    {
        while (k > 0)
        {
            int digit = k % 10;
            int sum = digit + carry;
            res.push_back(sum % 10);
            carry = sum / 10;
            k = k / 10;
        }
    }
    if (carry != 0)
    {
        res.push_back(carry);
    }
    reverse(res.begin(), res.end());
    return res;
}
void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> v;
    v.push_back(0);
    // v.push_back(2);
    // v.push_back(0);
    // v.push_back(0);
    int k = 34;
    vector<int> ans = addToArrayForm(v, k);
    printVector(ans);
    return 0;
}
