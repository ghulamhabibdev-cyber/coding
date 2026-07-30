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

char convert(char ch)
{

    int dif = ch - 'a';
    return 'A' + dif;
}
int countTrailZero(int number)
{
    int count = 0;
    while (number >= 5)
    {
        // count++;
        int ans = number / 5;
        count += ans;
        number /= 5;
    }
    return count;
}
bool isRectangel(int a,int b,int c,int d)
{
    if((a==b&&c==d)||(a==c||b==d)||(a==d&&c==b))
    {
        return true;
    }
    return false;
}

int main()
{
    // cout << convert('a');
    cout << countTrailZero(10) << endl;
    return 0;
}