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

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        cin >> str;
        if (str[0] == 'c' && str[2] == 'b')
        {
            cout << "NO" << endl;
        }
        else if (str[0] == 'b' && str[2] == 'a')
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }

    return 0;
}