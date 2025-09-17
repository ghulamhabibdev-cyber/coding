#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
void DoubleChck()
{
    ofstream myCheck;
    ifstream compare;
    int number;
    string  checkNum;
    compare.open("myCheck.txt",ios::app);
    myCheck.open("myCheck.txt");
    if(!compare||!myCheck){
        cout<<"Error.......!";
    }
    else{
    	while(!compare.eof()){
    	compare>>checkNum;
    		cout<<"MY NUMber is : "<<checkNum<<endl;
		}
	}
  


}
int main()
{
    DoubleChck();

}