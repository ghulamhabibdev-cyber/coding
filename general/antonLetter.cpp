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

int main() {
    int count=0;
    char ch;
    cin>>ch;
    bool arr[26]={0};
    while(ch!='}')
    {
        cin>>ch;
        if(ch>='a'&&ch<='z')
        {
            
            int curr=ch;
            int index=curr-'a';
            if(arr[index])
            {
                continue;
            }
            else{
                arr[index]=true;
                count++;
            }
        }
        
    }
    cout<<count<<endl;
    return 0;
}