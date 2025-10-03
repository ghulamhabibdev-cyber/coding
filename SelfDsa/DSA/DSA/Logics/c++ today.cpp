#include<iostream>
using namespace std;
void digitCheck(){
	int number;
	cout<<"Enter A number :\n";
	cin>>number;
	if(number>=1&&number<10){
		cout<<"ONE Digit Big\n";
	}
	else if(number>=10&&number<100){
		cout<<"Two Digit Big\n";
	}
	else{
		cout<<"Out Of Range\n";
	}
}
void dateCheck(){
	int date,month,year;
	bool checkLeap;
	cout<<"Enter date:\n";
	cin>>date;
	cout<<"Enter Month:\n";
	cin>>month;
	cout<<"Enter Year:\n";
	cin>>year;
	if(year%4==0&&year%100!=0){
		checkLeap=true;
	}
	else if(year%400==0){
		checkLeap=true;
	}
	else{
		checkLeap=false;
	}
	if(date>=1&&date<=31&&month==1){
		cout<<"Valid Date \n";
	}
	else if(date>=1&&date<=29&&month==2&&checkLeap==true){
		cout<<"Valid Date:\n";
	}
	else if(date>=1&&date<=28&&month==2&&checkLeap==false){
		cout<<"Valid Date :\n";
	}
	else if(date>=1&&date<=31&&month==3){
		cout<<"Valid Date\n";
	}
	else if(date>=1&&date<=30&&month==4){
		cout<<"Valid Date\n";
	}
	else if(date>=1&&date<=31&&month==5){
		cout<<"Valid Date\n";
	}
	else if(date>=1&&date<=30&&month==6){
		cout<<"Valid Date\n";
	}
	else if(date>=1&&date<=31&&month==7){
		cout<<"Valid Date\n";
	}
	else if(date>=1&&date<=31&&month==8){
		cout<<"Valid Date\n";
	}
	else if(date>=1&&date<=30&&month==9){
		cout<<"Valid Date\n";
	}
	else if(date>=1&&date<=31&&month==10){
		cout<<"Valid Date\n";
	}
	else if(date>=1&&date<=30&&month==11){
		cout<<"Valid Date\n";
	}
	else if(date>=1&&date<=31&&month==12){
		cout<<"Valid Date\n";
	}
	else {
			cout<<"InValid Date\n";
	}	
}
void checkCharater(){
	char a;
	int num;
	cout<<"Enter A chracter :\n";
	cin>>a;

	if(a>='0'&&a<='9'){
		cout<<"Number ";
		
		
	}
	else if(a>='a'&&a<='z'||a>='A'&&a<='Z'){
		cout<<"letters ";
	}
	else{
		cout<<"Symbols";
	}
}
void printPattern(){
	int num;
	do{
		cout<<"enter Number :\n";
		cin>>num;
	}while(num!=5);
	for(int i=1;i<=5;i++){
		for(int j=1;j<=i;j++){
			cout<<"+";
		}
		cout<<"\n";
	}
	for(int i=4;i>=1;i--){
		for(int j=i;j>=1;j--){
			cout<<"+";
		}
		cout<<"\n";
	}
}
void printTri(){
	int num;
	do{
		cout<<"Enter Number Of row\n";
		cin>>num;
	}while(num!=5);
	for(int i=0;i<=5;i++){
		for(int j=1;j<=(2*i)-1;j++){
			cout<<" +";
		}
		cout<<endl;
		for(int j=1;j<=8-2*i;j++){
			cout<<" ";
		}
//		cout<<"\n";/
	}
}
void lemonColor(){
	int color;
	int i=1;
	do{
		cout<<"what is Color of Lemen\n";
		cout<<"1 for red\n";
		cout<<"2 for yellow\n";
		cout<<"3 for greeen\n";
		cin>>color;
		if(color==2){
			cout<<"Win\n";
			cout<<"in "<<i<<" treis "<<endl;
			break;
		}
		i++;
	}while(i!=4);
//	cout<<""
}
int main()
{
//	digitCheck();
//	dateCheck();
//	checkCharater();
//	printPattern();
//	printTri();
	lemonColor();
	return 0;
}