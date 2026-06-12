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

class A {
};

int rememNumber(string number)
{
    const string pi="314159265358979323846264338327";
    int count=0;
    int i=0;
    while(i<number.length() && number[i]==pi[i])
    {
        count++;
        i++;
    }
    return count;
}
int main() {
    int t;
    cin >> t;
    while(t--)
    {
        string number;
        cin >> number;
        cout << rememNumber(number) << endl;
    }
    return 0;
}