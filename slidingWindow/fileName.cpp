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
int minNumberRemove(string fileName)
{
    int n = fileName.length();
    int low = 0;
    int mini = INT_MAX;
    int k = 3;
    int count = 0;
    while (low < n)
    {
        int curr = 0;
        int high = low;
        while (curr < k && high < n && fileName[high] == 'x')
        {
            curr++;
            high++;
        }
        if (curr >= k)
        {
            count++;
        }
        low++;
        count = min(mini, count);
    }

    return count;
}
int main()
{
        int len;
        cin>>len;
        string fileName;
        cin >> fileName;
        cout << minNumberRemove(fileName) << endl;
    
    return 0;
}