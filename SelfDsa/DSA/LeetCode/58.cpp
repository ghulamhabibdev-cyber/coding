#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};

int lengthOfLastWord(string s)
{

    pair<int, int> p;
    p.first = 0;
    bool get = true;
    int count = 0;
    bool found = true;
    bool lastFound = true;
    int last = s.length() - 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
       
        if (s[last] == ' ' && lastFound == true)
        {
            p.first = last;
            get = false;
            last--;
        }
        else if ((s[i] == ' ') && (found == true))
        {
            p.second = i;
            found = false;
        }
    }
    if (p.first == 0 && get == true &&found==false)
    {
       
        int ans = (s.length() - 1) - p.second;
        return ans;
    }
    else if (p.second != 0)
    {
        
        p.first = p.first - 1;
        int ans = p.first - p.second;
        return ans;
    }
    return s.length();
}
 int singleNumber(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1]&&i+1!=nums.size()-1)
            {
                return nums[i];
            }
            else if(nums[i]!=nums[i+1] && i+1==nums.size()-1)
            {
                return nums[i+1];
            }
        }
        return 1;
    }
int main()
{
    string name = "I";
    cout << "toal length : " << name.length() << endl;
    cout << lengthOfLastWord(name);

    return 0;
}