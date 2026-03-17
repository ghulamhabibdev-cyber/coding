#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {32, 34, 56, 45, 65, 76, 87, 98};
    cout << "Enter pos : " << " Must be less the :" << v.size() << endl;
    int pos;
    cin>>pos;
    int i = pos;
    int j = v.size() - 1;
    while (i < j)
    {
        swap(v[i], v[j]);
        i++;
        j--;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
