#include<iostream>
using namespace std;
void revers(int s,int e,string &str)
{
    if(s>e)
    {
        return ;
    }
    swap(str[s],str[e]);
    s++;
    e--;
    revers(s,e,str);
}
bool checkPalindrom(int i,int j,string str)
{
    if(i>j)
    {
        return true;
    }
    if(str[i]!=str[j])
    {
        return false;
    }
    else{
        return checkPalindrom(i+1,j-1,str);
    }
}
int main()
{
    string name="Babar";
    int e=name.length()-1;
    revers(0,e,name);
    cout<<name<<endl;
    string str="noefon";
    cout<<checkPalindrom(0,str.length()-1,str)<<endl;
    return 0;
}
