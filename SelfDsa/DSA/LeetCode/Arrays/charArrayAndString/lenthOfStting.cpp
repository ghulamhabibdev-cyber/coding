#include<iostream>
using namespace std;

int getLength(char arr[])
{
    int i=0;
    int count=0;
    while(arr[i]!=0)
    {
        count++;
        i++;
    }
    cout<<count;
    cout<<endl;
    return count;

}
int main()
{
    char name[]="Habib";
    cout<<getLength(name);
}