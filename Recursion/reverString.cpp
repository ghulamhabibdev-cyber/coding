#include <iostream>
using namespace std;

class A
{
};
void helper(string &str, int st, int end)
{
    if (st > end)
    {
        return;
    }
    swap(str[st], str[end]);
    helper(str, st + 1, end - 1);
}
void reverStr(string &str)
{
    int n = str.length();

    helper(str, 0, n - 1);
}
int main()
{
    string name = "Ali";
    reverStr(name);
    cout << name << endl;
    return 0;
}