#include<iostream>
using namespace std;
void RaisToPower(){
	int power,base;
	cout<<"Enter Base : \n";
	cin>>base;
	cout<<"Enter power :\n";
	cin>>power;
	int result=1;
	for(int i=1;i<=power;i++){
		result=base*base;
	}
	cout<<"raise to Power : "<<result<<endl;
}
int main()
{
	RaisToPower();
	
}