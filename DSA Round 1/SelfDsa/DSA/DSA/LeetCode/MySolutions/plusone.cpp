#include <bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int> &digits)
{
    int size = digits.size();

    int count = -1;
    if (digits[size - 1] == 9)
    {
        int i = size - 1;
        while (i >= 0 && digits[i] == 9)
        {

            digits[i] = 0;
            i--;
            count++;
        }
        if (count== size - 1)
        {
            digits[0] = 1;
            digits.push_back(0);
        }
        else
        {
            digits[i] += 1;
        }
    }

    return digits;
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
    v.push_back(9);
    v.push_back(9);
    v.push_back(9);
    v.push_back(2);
    v.push_back(9);
    v = plusOne(v);
    printVector(v);

    return 0;
}