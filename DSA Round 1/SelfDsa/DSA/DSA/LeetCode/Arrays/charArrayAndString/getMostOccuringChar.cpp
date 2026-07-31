#include<iostream>
using namespace std;
char getMostOccuringChar(string str)
{
    int arr[26]={0};
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        int number=0;
        if(ch>='a'&& ch<='z')
        {
            number=ch-'a';
        }
        else
        {
            number=ch-'A';
        }
        arr[number]++;
    }
    int max=-1;
    int ans=0;
    for(int i=0;i<26;i++)
    {
        if(max<arr[i])
        {
            ans=i;
            max=arr[i];
            

        }
    }
    char fin='a'+ans;
    return  fin;

}
int main()
{
    string test="test";
    cout<<getMostOccuringChar(test);
}