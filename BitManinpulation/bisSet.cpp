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
bool bitSet(int n, int post)
{
    int mask = 1 << post;
    return n & mask;
}
int main()
{
    int number;
    int post;
    cin >> number >> post;
    if (bitSet(number, post))
    {
        cout << "bit set ";
    }
    else
    {
        cout << "Zero " << endl;
    }
    return 0;
}