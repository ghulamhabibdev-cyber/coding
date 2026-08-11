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
bool isPermuation(string s1,string s2)
{
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2)
    {
        return true;
    }
    return false;
}
int main() {
    bool ans=isPermuation("ali","lia");
    if(ans)
    {
        cout<<"Permuation of each other";
    }
    else{
        cout<<"Not permuation of each other "<<endl;
    }
    return 0;
}