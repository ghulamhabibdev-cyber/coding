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
    char a = 'a';
    char A = 'A';
    for (int i = 1; i <= 26; i++)
    {
        int val = a;
        a++;
        cout << val<<" ";
    }
    cout<<"\n=============\n";
    for (int i = 1; i <= 26; i++)
    {
        int val = A;
    A++;
        cout << val<<" ";
    }
    return 0;
}