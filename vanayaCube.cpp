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
int maxHeightCubes(int n)
{
    int curr = 3;
    int sum = 0;
    int count = 0;
    while (sum < n)
    {
        sum += curr;
        curr = sum;
        count++;
    }
    return count;
}
int main()
{

    int n;
    cin >> n;
    cout << maxHeightCubes(n);

    return 0;
}