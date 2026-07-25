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
    if (num == n)
    {
        cout << num << endl;
        return;
    }
    cout << num << endl;
    printNumber(num + 1, n);
    cout << "This is Call Backtrack  : " << num <<" : "<< n - num << endl;
}
int main()
{
    int n = 5;
    printNumber(1, n);

    return 0;
}