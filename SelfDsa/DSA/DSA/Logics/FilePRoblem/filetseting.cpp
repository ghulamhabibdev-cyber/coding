#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream info;
    string line;
    info.open("habib.txt");
    if(!info){
        cout<<"Error............!";
    }
    else{
        while(!info.eof()){
            info>>line;
            cout<<line;
        }
        
    }
}