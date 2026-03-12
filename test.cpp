#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    int getCount(string url)
    {
        int num = 0;
        int i = 0;
        while (url[i] != ' ')
        {
            int digit = url[i] - '0';
            num = num * 10 + digit;
            i++;
        }
        return num;
    }

    vector<string> getAllDomain(string url)
    {
        int i = 0;
        while (url[i] != ' ')
        {
            i++;
        }

        string domain = url.substr(i + 1);

        vector<string> v;
        v.push_back(domain);

        for (int j = 0; j < domain.size(); j++)
        {
            if (domain[j] == '.')
            {
                v.push_back(domain.substr(j + 1));
            }
        }
        return v;
    }

    vector<string> subdomainVisits(vector<string> &cpDomains)
    {
        unordered_map<string, int> mp;

        for (string currUrl : cpDomains)
        {
            int num = getCount(currUrl);
            vector<string> v = getAllDomain(currUrl);

            for (string sub : v)
            {
                mp[sub] += num;
            }
        }

        vector<string> ans;

        for (auto &p : mp)
        {
            ans.push_back(to_string(p.second) + " " + p.first);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<string> v = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};

    vector<string> ans = s.subdomainVisits(v);

    for (string str : ans)
    {
        cout << str << endl;
    }

    return 0;
}