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

void towerOfHanoi(int n, int src, int help, int dest)
{
    // Base Case: Only one disk to move
    if (n == 1)
    {
        cout << "move disk 1 from " << src << " to " << dest << endl;
        return; 
    }

    towerOfHanoi(n - 1, src, dest, help);
    cout << "move disk " << n << " from " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, help, src, dest);
}

int main()
{
    int numberOfDisks = 3;
    towerOfHanoi(numberOfDisks, 1, 2, 3);
    return 0;
}
