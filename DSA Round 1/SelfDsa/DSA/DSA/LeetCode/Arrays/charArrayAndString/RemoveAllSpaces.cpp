#include<iostream>
using namespace std;
string RemoverspaceAddThis(string str,string sym)
{
    string temp="";
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==' ')
        {
            for(int j=0;j<sym.length();j++)
            {
                temp.push_back(sym[j]);

            }
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    return temp;
}
int main()
{
 string name="My Name Is Ghulam habib";
 cout<<RemoverspaceAddThis(name,"@40");
}