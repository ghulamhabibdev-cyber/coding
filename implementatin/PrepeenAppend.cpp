#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        int k = 0;
        int j = len - 1;
        int count = 0;
        string str;
        cin >> str;
        bool found = false;
        while ((str[j] == '0' && str[k] == '1') || (str[j] == '1' && str[k] == '0'))
        {
            k++;
            j--;
            found = true;
            if(k>j||j<k)
            {
                break;
            }
        }
        if (found)
        {
            count = j - k;
            count++;
        }
        else
        {
            // cout << "Not Found " << k << endl;
            count = ++j;
        }

        cout << count << endl;
    }
    return 0;
}