#include<iostream>
#include<math.h>
using namespace std;
void StandradDeviation(int arr[5]){
    
    double mean;
    for(int i=0;i<5;i++){
        mean+=arr[i];
    }
    mean=mean/5;
    cout<<"Mean : "<<mean<<endl;
    double diffArray[5];
    for(int i=0;i<5;i++){
        diffArray[i]=arr[i]-mean;
        
    }
    double meanDeviateSum=0;
    for(int i=0;i<5;i++){
        diffArray[i]=diffArray[i]*diffArray[i];
        
        meanDeviateSum+=diffArray[i];
        
    }

    meanDeviateSum=meanDeviateSum/5;
    double result=sqrt(meanDeviateSum);
    cout<<"Standard Deviation : "<<result<<endl;
}
int main()
{
    
    int arr[5]={40,44,45,43,47};
    StandradDeviation(arr);
}