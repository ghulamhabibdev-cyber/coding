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
bool isValid(vector<int> &alph, char ch, int k)
{
    for (int i = 0; i < 26; i++)
    {
        // cout << alph[i] << endl;
        if (alph[i] < k)
        {
            return false;
        }
    }
    return true;
}
int longestSubstring(string s, int k)
{
    int n = s.length();
    int high = 0;
    vector<int> alph(26, 0);
    int low = 0;
    int len = INT_MIN;
    while (high < n)
    {
        char ch = s[high];
        int index = ch - 'a';
        // cout << ch << endl;
        alph[index]++;
        high++;
        bool tr = true;
        for (int i = low; i < high; i++)
        {
            char c = s[i];
            if (!isValid(alph, c, k))
            {

                tr = false;
                break;
            }
        }
        // cout << "WHile tr" << endl;
        while (tr)
        {
            cout << "Here";
            char ch = s[high];
            high++;
            index = ch - 'a';
            alph[index]++;
            if (!isValid(alph, ch, k))
            {
                tr = false;
                
                alph[low]--;
                low++;
                break;
            }
            int curr = high - low + 1;
            // cout << "I am curr : " << curr << endl;
            len = max(curr, len);
        }
        
    }
    return len;
}
int main()
{
    string s = "ababbc";
    int k = 3;
    int ans = longestSubstring(s, k);
    cout << ans << endl;

    return 0;
}