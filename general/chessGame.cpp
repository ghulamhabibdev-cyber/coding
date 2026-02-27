#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A {
};
pair<int,int> countGames(string str)
{
    int antonCount=0;
    int danikCount=0;
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        if(str[i]=='A')
        {
            antonCount++;
        }
        else{
            danikCount++;
        }
    }
    return {antonCount,danikCount};
}
int main() {
    int n;
    cin>>n;
    string games;
    cin>>games;
    pair<int,int>p=countGames(games);
    if(p.first>p.second)
    {
        cout<<"Anton";
    }
    else if(p.first<p.second)
    {
        cout<<"Danik";
    }
    else{
        cout<<"Friendship";
    }
    
    return 0;
}