#include <bits/stdc++.h>
using namespace std;
void  reverseString(string &str,int i,int j)
{
  if(i>j)
  {
    return;
  }
   swap(str[i],str[j]);
   i++;
   j--;
   reverseString(str,i,j);
}

string revstr(string str)
{
    int i = 0;
    int j = str.length() - 1;
    while (i <= j)
    {
        char a = str[j];
        str[j] = str[i];
        str[i] = a;
        i++;
        j--;
    }
    return str;
}

int main()
{
    // cout<<revstr("Habib");
    string name="habib";
    reverseString(name,0,name.length()-1);
    cout<<name<<endl;
    return 0;
}