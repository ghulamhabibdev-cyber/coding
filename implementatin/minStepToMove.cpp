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
int findLissPosstion(string str, string instr)
{
    int n = instr.length();
    int i = 0;
    int count = 1;
    int index = 0;
    while (i < n)
    {
        char ch = str[index];
        char c = instr[i];
        if (ch == c)
        {
            count++;
            index++;
        }
       
        i++;
    }
    return count;
}
int main()
{
    string str;
    string instr;
    cin >> str;
    cin >> instr;
    int currPosition = findLissPosstion(str, instr);
    cout << currPosition << endl;

    return 0;
}