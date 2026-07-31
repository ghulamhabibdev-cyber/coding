#include<iostream>
using namespace std;
int main(){
	int count=0;
	int arr[5]={23,43,23,34,23};
	for(int i=0;i<5;i++){
		if(arr[i]==23){
			count++;
		}
	}
	cout<<"this Number exist : "<<count<<endl;
	int arr1[count+2];
	int adder=0;
	for(int i=0;i<5;i++){
		if(arr[i]==23){
			
			arr1[adder]=arr[i];
			adder++;
		}
	}
	for(int i=0;i<count+2;i++){
		cout<<arr1[i]<<"\t";
	}
}