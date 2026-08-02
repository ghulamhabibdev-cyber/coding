#include<bits/stdc++.h>
using namespace std;
class  a
{

};
void setValues(int *p,int n)
{
    for(int i=0;i<n;i++)
    {
        *p=i;
        p++;
    }

}
void printValues(int *p,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<(*p)<<endl;
        p++;
    }

}
void mainPulate(int *p,int n)
{
    for(int i=0;i<n;i++)
    {
        *p=i*3+((i+4)/2)*3/2;
        p++;
    }

}
int main()
{
    int *p=new int[100];
    setValues(p,100);
    printValues(p,100);
    mainPulate(p,100);
    printValues(p,100);

    return 0;
}
