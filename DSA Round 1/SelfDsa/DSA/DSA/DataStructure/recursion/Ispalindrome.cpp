#include <bits/stdc++.h>
using namespace std;
bool Isplidrom(string str)
{
    if(str.length()==0||str.length()==1)
    {
        return true;
    }
    if(str.at(0)==str.at(str.length()-1))
    {
        return Isplidrom(str.substr(1,str.length()-2));
    }
    return false;

}
int main()
{
   cout<< Isplidrom("NON");
  
    return 0;
}