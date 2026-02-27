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
        int number;
        cin >> number;
        int sumOfDigit = 0;
        while (number != 0)
        {
            int digit = number % 10;
            sumOfDigit += digit;
            number /= 10;
        }
        cout << sumOfDigit << endl;
    }
    return 0;
}