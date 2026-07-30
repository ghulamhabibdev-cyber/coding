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
    int redNumberOfSocks;
    int blueNumberOfSocks;
    cin >> redNumberOfSocks >> blueNumberOfSocks;
    int mini = min(redNumberOfSocks, blueNumberOfSocks);
    int sameWear = max(redNumberOfSocks, blueNumberOfSocks) - mini;
    sameWear = sameWear / 2;
    cout << mini << " " << sameWear << endl;

    return 0;
}