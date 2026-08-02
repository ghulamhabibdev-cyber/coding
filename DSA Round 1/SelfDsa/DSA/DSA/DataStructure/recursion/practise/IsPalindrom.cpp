#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string str)
{
    if(str.length()==0||str.length()==1)
    {
        return true;
    }
    if(str.at(0)==str.at(str.length()-1)) 
    {
        return isPalindrome(str.substr(1,str.length()-2));
    }
    return false;
}
int main()
{
    cout<<isPalindrome("AABB");
  
    return 0;
}
