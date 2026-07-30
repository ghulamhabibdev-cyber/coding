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
    int t;
    cin >> t;
    int base = 10;
    // cout << endl;
    vector<pair<int, vector<int>>> arr;
    while (t--)
    {
        long long number;
        long base = 10;
        cin >> number;
        int count = 0;
        vector<int> numbers;
        while (base <= number)
        {
            int roundNum = number % base;
            number = number - roundNum;
            if (roundNum > 0)
            {
                // cout << roundNum << " ";
                numbers.push_back(roundNum);
                count++;
            }
            base *= 10;
        }
        // cout << endl;
        cout << ++count << endl;
        ;
        numbers.push_back(number);
        for (int x : numbers)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}