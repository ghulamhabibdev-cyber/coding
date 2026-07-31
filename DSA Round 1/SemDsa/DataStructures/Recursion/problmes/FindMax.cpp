#include<bits/stdc++.h>
using namespace std;
class  a
{

};
int largestOfArray(int arr[],int first,int last)
{
    int max;
    if(first==last)
    {
        return arr[first];
    }
    else{
        max=largestOfArray(arr,first+1,last);
        if(arr[first]>=max)
        {
            return arr[first];
        }
        else{
            return max;
        }
    
    }
}
int main()
{

    cout<<"Find The Max Of Array \n";
    int arr[5]={12,343,32,32,43};
    cout<<"Max Of arr   : "<<largestOfArray(arr,0,4)<<endl;
    return 0;
}
