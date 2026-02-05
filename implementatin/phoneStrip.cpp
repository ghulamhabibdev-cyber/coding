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
    int arr[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }
    string str;
    cin >> str;
    int totalWastedCal = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int pos = str[i] - '0';
        totalWastedCal += arr[pos-1];
    }
    cout << totalWastedCal << endl;
    return 0;
}