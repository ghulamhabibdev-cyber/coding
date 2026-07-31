#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s)
{

    long long int number = 0;
    string num;
    int i = 0;
    int sign = 1;
    while (i != s.length())
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            i++;
            continue;
        }
        else if (s[i] == ' ')
        {
            i++;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            num += s[i];
            i++;
        }
        else if (s[i] == '.')
        {
            break;
        }
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
        {
            sign = 1;
            i++;
        }
    }
    i = 0;
    while (i != num.length())
    {
        int digit = num[i] - '0';
        number = number * 10 + (digit);
        i++;
        /* code */
    }
    if (sign == 1 && number > INT_MAX)
        return INT_MAX;
    if (sign == -1 && -number < INT_MIN)
        return INT_MIN;

    cout << "Number : " << number << endl;
    return (number * sign);
}
int main()
{
    cout << myAtoi("+-12");
    return 0;
}