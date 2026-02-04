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
int fibNumber(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibNumber(n - 1) + fibNumber(n - 2);
}
int main()
{
    int n;
    cout <<"Enter A Number : "<<endl;
    cin>>n;
    int num = fibNumber(n > 0 ? n : 5);
    cout << num << endl;
    return 0;
}