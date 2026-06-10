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
long long pairSum(int a, int b)
{
    return a + b;
}
int pairSumSequence(int n)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pairSum(i, i + 1);
    }
    return sum;
}

int main()
{
    int n = 5;
    
    int ans = pairSumSequence(100);
    cout << ans << endl;

    return 0;
}