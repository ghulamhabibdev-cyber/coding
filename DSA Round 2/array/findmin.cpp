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
    int arr[5] = {1, 32, 34, 4, -34};
    int min = arr[0];
    int index = 0;
    for (int i = 1; i < 5; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    }
    cout << index << endl;
    cout << min << endl;
    return 0;
}