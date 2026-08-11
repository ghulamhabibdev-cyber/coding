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
int count(string str)
{
    int count = 0;
    for (char ch : str)
    {
        if (ch != ' ')
        {
            count++;
        }
    }
    return count;
}
int spaceCounter(string str, int validIndex)
{
    int spaceCount = 0;
    for (int i = 0; i < validIndex; i++)
    {
        char ch = str[i];
        if (ch == ' ')
        {
            spaceCount++;
        }
    }
    return spaceCount;
}
void addStrSapce(string &str)
{

    int len = str.length();
    cout << len << endl;
    int i = len - 1;

    while (i > 0 && str[i] == ' ')
    {
        i--;
    }
    cout << i << endl;
    int count = spaceCounter(str, i);
    int index = (i + 1) + count * 2;

    for (int j = i; j >= 0; j--)
    {
        char ch = str[j];
        if (ch == ' ')
        {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index -= 3;
        }
        else
        {
            str[index - 1] = str[j];
            index--;
        }
    }
    

}
int main()
{
    string str = "ali al   ";
    addStrSapce(str);
    cout << str << endl;

    return 0;
}