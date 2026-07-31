#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 13;
    stack<int> st;
    int temp = n;
    while (temp > 0)
    {
        int bit = temp % 2;
        st.push(bit);
        temp /= 2;
    }

    int complementedBinary = 0;
    while (!st.empty())
    {
        int bit = st.top();
        st.pop();
        bit = (bit == 0) ? 1 : 0; // Flip bit
        complementedBinary = complementedBinary * 10 + bit;
    }
    int compNum = 0;
    int base = 1;
    while (complementedBinary > 0)
    {
        int bit = complementedBinary % 10;
        compNum += bit * base;
        base *= 2;
        complementedBinary /= 10;
    }
    cout << compNum << endl;
    return compNum;

    return 0;
}
