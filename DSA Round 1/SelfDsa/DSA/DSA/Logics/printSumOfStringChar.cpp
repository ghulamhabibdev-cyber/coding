#include<iostream>
using namespace std;
void SumOFCharOfSting(string str)
{
    int len=0;
     
    cout<<"lemntgh is : "<<str.length()<<endl;
    char chr;
    int sum=0;
    for(int i=0;i<str.length();i++)
    {
        chr=str[i];
        sum+=int(chr);

    }
    cout<<"Sum Of All Char is : "<<sum<<endl;
    

}
int main()
{
    string str;
    cout<<"Enter String : \t";
    getline(cin,str);
    SumOFCharOfSting(str);
}