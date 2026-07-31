#include <bits/stdc++.h>
using namespace std;
int main()
{
    string name="hello world habib ali";
    int len=0;
    int i=0;
    int space=0;
    int j=0;
    while (name[i]!='\0')
    {
        len++;
        if(name[i]==' ')
        {
                space++;
                j=i;
        }
        i++;
    }
    cout<<"TOtal Len : "<<len<<endl;
    cout<<"TOtal spaces : "<<space<<endl;
    cout<<"INdex : "<<j<<endl;
    int lastLen=0;
    for(int i=j+1;i<len;i++)
    {
        lastLen++;
    }
    cout<<lastLen;
    

    return 0;
}