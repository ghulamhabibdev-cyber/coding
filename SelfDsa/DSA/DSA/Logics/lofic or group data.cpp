#include<iostream>
using namespace std;
int main()
{
	int uper,lower;
	cout<<"ENter Lower Limit : \n";
	cin>>lower;
	cout<<"Enter Upwer Limit :\n";
	cin>>uper;
	int sum=0;
	for(int i=lower;i<=uper;i++){
		sum+=i;
	}
	cout<<sum<<endl;
	cout<<sum/(uper-lower);
	
}