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
bool checkPlayerMove(vector<string>playerCard,string tableCard)
{
    int n=playerCard.size();
    for(int i=0;i<n;i++)
    {
        string card=playerCard[i];
        char rank=card[0];
        char suit=card[1];
        if((rank==tableCard[0]||rank==tableCard[1])||suit==tableCard[0]||suit==tableCard[1])
        {
            return true;
        }
    }
    return false;
}
int main() {
    string tableCard;
    cin>>tableCard;
    int n=5;
    vector<string>playerCard(n);
    for(int i=0;i<n;i++)
    {
        cin>>playerCard[i];
    }
    bool canPlay=checkPlayerMove(playerCard,tableCard);
    if(canPlay)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}