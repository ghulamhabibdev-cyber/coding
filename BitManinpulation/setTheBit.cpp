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
void setBit(int &n, int post)
{
    int mask = 1 << post;
    n = n | mask;
}
int main()
{
    int n = 8;
    setBit(n, 2);
    cout << n << endl;
    return 0;
}