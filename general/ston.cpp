#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
int countToMakeDiffColr(string str)
{
    int count = 0;
    int n = str.length();
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    cout<<countToMakeDiffColr(str);

    return 0;
}