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
bool helper(string str, int st, int end)
{
    if (st > end)
    {
        return true;
    }
    if (str[st] != str[end])
    {
        return false;
    }
    return helper(str, st + 1, end - 1);
}
bool isPalindrome(string &str)
{
    int n = str.length() - 1;
    return helper(str, 0, n);
}
char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch - 'A' + 'a';
    }
    return ch;
}
char toUpper(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        ch = ch - 'a' + 'A';
    }
    return ch;
}
bool isVowel(char ch)
{
    ch = toLower(ch);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        return true;
    }
    return false;
}
int countVowels(string str, int index = 0)
{
    if (index >= str.length())
    {
        return 0;
    }
    if (isVowel(str[index]))
    {
        return 1 + countVowels(str, index + 1);
    }
    return countVowels(str, index + 1);
    ;
}
void reverseHelper(string &str, int st, int end)
{
    if (st > end)
    {
        return;
    }
    swap(str[st], str[end]);
    reverseHelper(str, st + 1, end - 1);
}
void reverseStr(string &str)
{
    int n = str.length() - 1;
    reverseHelper(str, 0, n);
}
void helperLowerToUpper(string &str, int index)
{
    if (index >= str.length())
    {
        return;
    }
    helperLowerToUpper(str, index + 1);
    char ch = toUpper(str[index]);
    str[index] = ch;
}
void lowerToUpper(string &str)
{
    helperLowerToUpper(str, 0);
}
int main()
{
    string str = "Hello";
    // if (isPalindrome(str))
    // {
    //     cout << "It Palindrome " << endl;
    // }
    // else
    // {
    //     cout << "It not Palindrome" << endl;
    // }
    // cout << "Total Vowels " << countVowels(str, 0) << endl;
    // reverseStr(str);
    lowerToUpper(str);
    cout << str << endl;
    return 0;
}