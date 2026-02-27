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
bool isLetter(char ch)
{
    return (ch>='a'&&ch<='z');
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string word="";
        for(int i=0;i<8;i++)
        {
            for(int i=0;i<8;i++)
            {
                char ch;
                cin>>ch;
                if(isLetter(ch))
                {
                    word+=ch;
                }

            }
        }
        cout<<word<<endl;
    }
    return 0;
}