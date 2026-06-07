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
int findMax(vector<int> &nums) {
    int max_val = INT_MIN;
    for (int num : nums) {
        max_val = max(max_val, num);
    }
    return max_val;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin>>nums[i];
        }
        cout<<findMax(nums)<<endl;
    }
    return 0;
}