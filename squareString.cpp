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

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        unordered_map<char, bool> mp;
        string str;
        cin >> str;
        if (str.length() % 2 == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        int n = str.length();
        int idx = 0;
        string word = "";
        for (int j = 0; j < n; j++)
        {
            char ch = str[j];
            if (mp.find(ch) != mp.end())
            {
                idx++;
                break;
            }
            else
            {
                mp[ch] = true;
                word += ch;
                idx++;
            }
        }

        string Nextword = "";
        int lenCount = 0;
        int len = word.length();
        int wordCount = 0;
        bool checkFlag = true;
        while (idx < n)
        {
            char ch = str[idx];
            if (lenCount == len)
            {
                if (Nextword == word)
                {
                    Nextword = "";
                    wordCount++;
                }
                else
                {
                    cout << "NO" << endl;
                    wordCount = 5;
                    break;
                }
            }
            if (mp.find(ch) != mp.end())
            {
                lenCount++;
                Nextword += ch;
            }
            else
            {
                cout << "NO" << endl;
                checkFlag = false;
                break;
            }
            idx++;
        }
        if (checkFlag && wordCount % 2 == 0)
        {
            cout << "I am Har" << wordCount << endl;
            cout << "Yes" << endl;
        }
    }
    return 0;
}