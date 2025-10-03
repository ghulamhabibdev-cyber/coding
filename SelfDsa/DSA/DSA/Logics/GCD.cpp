#include<iostream>
using namespace std;
void findGCD(){
	int num1,num2,rem=1;
	cout<<"Enter Number :\n";
	cin>>num1;
	cout<<"Enter Number :\n";
	cin>>num2;
	while(rem!=0){
		rem=num1%num2;
		cout<<"REM :"<<rem<<endl;
		if(rem!=0){
			num1=num2;
			num2=rem;
		}
		if(rem==0){
			cout<<" Common Divisor :"<<num2;
		}
	}
	
}
void findLCM(){
	int number;
	int number2;
	int rem;
	int rem2;
	int product=1;
	cout<<"enter Number :\n";
	cin>>number;
	cout<<"enter Number :\n";
	cin>>number2;
	for(int i=2;i<=number;i++){
		for(int j=2;j=)
		rem=number%i;
		rem2=number2%i;
		if(rem==0&&rem2==0){
			number=number/i;
			number2=number2/i;
			product*=i;
//			cout<<number*i<<endl;
			cout<<"Product :"<<product<<endl;
		}
		if(number==1&&number2==1){
			break;
		}
	}
}
int main(){
//	findGCD();
	findLCM();
	return 0;
}