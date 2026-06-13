#include <iostream>
#include <vector>
#include <map>
using namespace std;

string mapWordWeights(vector<string> &words, vector<int> &weights)
{
    int n = words.size();
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string currWord = words[i];
        int j = 0;
        int len = currWord.length();
        long long sum = 0;
        while (j < len)
        {
            char ch = currWord[j];
            int index = ch - 'a';

            sum += weights[index];
            j++;
        }
        mp[currWord] = sum;
    }
    string res = "";
    for (int i = 0; i < n; i++)
    {
        int sum = mp[words[i]];
        int mod = sum % 26;
        char ch = 'z' - mod;
        res += ch;
    }
    return res;
}

int main()
{
    vector<string> words = {"abcd", "def", "xyz"};
    vector<int> wts = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8, 7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2};
    string ans = mapWordWeights(words, wts);
    cout << ans << endl;
}