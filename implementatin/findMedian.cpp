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
    string str = "12.00";
    int i = 0;
    while (str[i] != '.')
    {
        i++;
    }
    cout << i << endl;
    return 0;
}