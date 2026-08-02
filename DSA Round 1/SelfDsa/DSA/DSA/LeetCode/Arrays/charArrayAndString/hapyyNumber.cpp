#include<iostream>
#include<vector>
using namespace std;
bool happyNumber(int x)
{
    vector<int> v;
    int ans=0;
    while (true)
    {
        int rem=x%10;
        cout<<"Rem : "<<rem<<endl;
        v.push_back(rem);
        x=x/10;
        if(x==0)
        {
            for(int i=0;i<v.size();i++)
            {
                x+=v[i]*v[i];
                cout<<" X : "<<x<<endl;
                if(x==1)
                {
                    return x;
                }

            }
            
        }
    }
    
    return 0;
   
}
int main()
{
    cout<<happyNumber(19);
    // cout<<" 10 "<<(2/10)<<endl;
}