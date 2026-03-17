#include <iostream>
#include <vector>
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
    vector<int> arr(4);   // vector of 4 size
    vector<int> as(4, 2); // vector of 4 size each element of 2
    // push_back is use of put value in vector
    vector<int> Q = {32, 3, 3, 432, 323, 23, 23, 2, 42, 32, 3232, 323};
    sort(Q.begin(), Q.end(), greater<int>());
    for(int a:Q)
    {
        cout<<a<<" ";
    }
    return 0;
}