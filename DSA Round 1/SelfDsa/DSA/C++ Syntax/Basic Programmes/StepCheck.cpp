#include<iostream>
using namespace std;
void CheckStep(int noOfSteps)
{
    if(noOfSteps<0){
        cout<<"Enter Correcrt No Steps "<<endl;
    }
    else if(noOfSteps>=10000)
    {
        cout<<"Goal Acieved ! "<<endl;
    }
    else if(noOfSteps>=8000&& noOfSteps<=9999)
    {
        cout<<"Almost There ! "<<endl;
    }
    else{
        cout<<"keep going !"<<endl;
    }
}
int main()
{
    int noOfSteps;
    cout<<"Enter No of Steps : "<<endl;
    cin>>noOfSteps;
    CheckStep(noOfSteps);
    return 0;
}