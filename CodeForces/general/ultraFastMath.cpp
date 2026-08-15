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
// long int getNum(string num1)
// {
//     long int sum = 0;
//     int n = num1.length();
//     long long pow = 1;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         int bit = num1[i] - '0';
//         sum += pow * bit;
//         pow *= 2;
//     }
//     return sum;
// }
// string getBinary(long int num,int len)
// {
//     string ans = "";
//     while (num != 0)
//     {
//         int bit = num % 2;
//         char ch = bit + '0';
//         num/=2;
//         ans += ch;
//     }
//     int ansLen=ans.length();
//     while(ansLen!=len)
//     {
//         ans+='0';
//         ansLen++;
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
// }
string xorFun(string num1, string num2)
{
    int len = num1.length();
    // long int num11 = getNum(num1);
    // long int num21 = getNum(num2);
    // long int ans = num11 ^ num21;

    // string newNum = getBinary(ans,len);
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        if (num1[i] == num2[i])
        {
            ans += '0';
        }
        else
        {
            ans += '1';
        }
    }
    return ans;
    ;
}
int main()
{
    string num1;
    string num2;
    cin >> num1;
    cin >> num2;
    string ans = xorFun(num1, num2);
    cout << ans;

    return 0;
}