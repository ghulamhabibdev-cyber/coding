#include <iostream>
#include<vector>
using namespace std;

class A {
};
int distincChar(string str)
{
    vector<bool>check(26,false);
    int n=str.length();
    int count=0;
    for(char c:str)
    {
         char ch = tolower(c);
        int index = ch - 'a';

        if (!check[index])
        {
            check[index] = true;
            count++;
        }
    }
    return count;
}
int main() {
    string name;
    cin>>name;
    int count=distincChar(name);
    // cout<<count<<endl;
    if(count&1)
    {
 cout<<"IGNORE HIM!";
    }
    else{
         cout<<"CHAT WITH HER!";
      
    }
    
    return 0;
}