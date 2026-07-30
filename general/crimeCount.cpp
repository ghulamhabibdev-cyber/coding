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
    int personCount = 0;
    int crimeCount = 0;
    for (int i = 0; i < n; i++)
    {
        int event;
        cin >> event;
        if (personCount >= 0 && event > 0)
        {
            personCount += event;
        }
        else if (personCount <= 0 && event == -1)
        {
            crimeCount++;
        }
        else if (personCount > 0 && event == -1)
        {
            personCount--;
            // crimeCount--;
        }
    }
    // cout<<"q";
    cout << crimeCount << endl;
    return 0;
}