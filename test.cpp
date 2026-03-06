#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
#include <time.h>
#include <cstdlib>
#include <ctime>
// typedef string url;
using namespace std;

class Solution
{
public:
    string firstPart = "";
    unordered_map<string, string> mp;
    vector<string> recordUrl;
    // Encodes a URL to a shortened URL.

    string randomWord(int t = 5)
    {
        srand(time(0));
        string word = "";

        for (int i = 0; i < t; i++)
        {
            char ch = 'a' + rand() % 26;
            word += ch;
        }

        return word;
    }
    void createdFirstPart(string url)
    {
        int count = 0;
        int index = 0;
        while (count != 2 && url[index] != '/')
        {
            char ch = url[index];
            index++;
            firstPart += ch;
            if (ch == '/')
            {
                count++;
            }
        }
    }
    string encode(string longUrl)
    {
        createdFirstPart(longUrl);
        int index = firstPart.length();
        int n = longUrl.length();
        int num = rand() % 10;
        string shortUrl = firstPart;
        shortUrl += randomWord(num);
        cout << shortUrl << endl;
        shortUrl += '/';
        cout << shortUrl << endl;

        while (index < n)
        {
            string currWord = "";
            int currIndex = index;
            while (currIndex < n && longUrl[currIndex] != '/')
            {
                char ch = longUrl[currIndex];
                currIndex += 1;
                currWord += ch;
                index++;
            }
            cout << currWord << endl;
            currWord += longUrl[currIndex];
            int currWordLen = currWord.length();
            string ch = currWord.substr(0, currWordLen / 2 + 1);
            recordUrl.push_back(ch);

            mp[ch] = currWord;
            cout << currWord << endl;
            index++;
            shortUrl += ch;
        }
        cout << shortUrl << endl;
        // cout << recordUrl << endl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        string longUrl = firstPart;
        for (string ch : recordUrl)
        {
            longUrl += mp[ch];
        }
        return longUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
int main()
{

    Solution s;
    string google = "https://leetcode.com/problems/encode-and-decode-tinyurl/?envType=problem-list-v2&envId=string";
    string goo = s.encode(google);
    cout << goo << endl;
    cout << s.decode(goo);
    return 0;
}