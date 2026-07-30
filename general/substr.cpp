#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
#include <string>
#include <cstdlib>
using namespace std;

class A
{
};

int main()
{
    // string descrtion = "Hello world My Name is all";
    // string part = descrtion.substr(6,5);
    // cout << part << endl;
    string str;
    cout << "Enter a Text " << endl;
    getline(cin, str);
    int len = str.length();
    cout << "Enter A start posion less ten : " << len << endl;
    int pos;
    cin >> pos;
    int charCount;
    cout << "Enter Number of char less then : " << len << endl;
    cin >> charCount;
    string part = str.substr(pos, charCount);
    cout << part << endl;

    return 0;
}