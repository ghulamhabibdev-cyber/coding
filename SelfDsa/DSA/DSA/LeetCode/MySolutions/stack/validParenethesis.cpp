#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<char> br;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            br.push(s[i]);
        }
        else
        {
            if (s[i] == ')')
            {
                char check = br.top();
                if (check == '(' && s[i] == ')')
                {
                    br.pop();
                }
            }
            if (s[i] == '}')
            {
                char check = br.top();
                if (check == '{' && s[i] == '}')
                {
                    br.pop();
                }
            }
            if (s[i] == ']')
            {
                char check = br.top();
                if (check == '[' && s[i] == ']')
                {
                    br.pop();
                }
            }
        }
    }
    if (!br.empty())
    {
        return true;
    }
    return false;
}
int main()
{

    return 0;
}