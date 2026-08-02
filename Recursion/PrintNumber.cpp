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
void printNumber(int num, int n)
{
    if (num > n)
    {
        printNumber(num - 1, n);
        cout << num << endl;
        return;
    }
    if (num == n)
    {
        cout << num << endl;
        return;
    }
    cout << num << endl;
    printNumber(num + 1, n);
}
int main()
{
    int n = -5;
    printNumber(-10, n);

    return 0;
}