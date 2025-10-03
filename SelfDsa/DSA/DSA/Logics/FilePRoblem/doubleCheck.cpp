#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
using namespace std;
void DoubleChck()
{
	ifstream file;
	bool flag=true;
	ofstream input;
	input.open("hello.txt",ios::app);
	int id;
	vector<int> myVec;
	int num1;
	file.open("hello.txt");
	string num;
	if(!file.is_open()){
		cout<<"Error........!";
	}
	while(getline(file,num))
	{
		num1=atoi(num.c_str());
	myVec.push_back(num1);		
	}
	cout<<"Enter ID Number :";
	cin>>id;
	for(int num:myVec)
	{
		if(num==id)
		{
			cout<<"match";
			flag=false;
		}
		
	}
	if(flag==true){
			input<<id<<"\n";
			cout<<"id is added.............\n";
		
	}

}
int main()
{
    DoubleChck();

}