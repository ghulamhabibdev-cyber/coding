#include<iostream>
#include<math.h>
using namespace std;
void relative(){
    double arr[5]={2,34,54,5,67};
    double relArr[5];
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=arr[i];
    }
    for(int i=0;i<5;i++)
    {
        relArr[i]=arr[i]/sum;
    }
    for(double i:relArr){
        cout<<i<<"\t";
    }
    
}
int main(){
    relative();
}