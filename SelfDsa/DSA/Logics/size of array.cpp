#include<iostream>
using namespace std;

void sizarray(int array[]){
	for(int i=0;i<4;i++){
		cout<<array[i]<<endl;
	}

	int len=0;
	cout << "SIZE : " << sizeof(array) << endl;
	cout << "SIZE1 : " << sizeof(array[1]) << endl;
	len=sizeof(array)/sizeof(array[1]);
	cout << "LEN : " << len << endl;
	cout<<"Size if array : "<<len<<endl;
	for(int i=0;i<4;i++){
		cout<<"Elements are : "<<array[i]<<endl;
		
	}
	
}
int main(){
	int arr[4]={23,3423,43,54};
	int len=sizeof(arr)/sizeof(arr[1]);
	cout<<"in main :"<<len<<endl;
	sizarray(arr);
}