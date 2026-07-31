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

class A {
};
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.length();
        int low=0;
        int maxLen=0;
        unordered_map<char, int> freq;
        for(int high=0; high<n; high++) {
            freq[s[high]]++;
            while(freq.size() > k) {
                freq[s[low]]--;
                if(freq[s[low]] == 0) {
                    freq.erase(s[low]);
                }
                low++;
            }
            if(freq.size() == k) {
                maxLen = max(maxLen, high - low + 1);
            }
        }
        return maxLen;
    }
};
int main() {
    cout<<(3%3)<<endl;
    
    return 0;
}