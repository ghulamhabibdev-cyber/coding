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
    int amount;
    cin>>amount;
    int r;
    cin>>r;
    for (int x = 1; x <= 10; x++)
    {
        int total = amount * x;
        if (total % 10 == 0 || total % 10 == r)
        {
            cout << x;
            break;
        }

   }
    return 0;
}