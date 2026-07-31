#include<iostream>
using namespace std;
int main()
{
    int width,height;
        char symbol,choice;
        int type;
        
    do{
        
        cout<<"Enter Height Of Rectangele : \n";
        cin>>height;
        cout<<"Enter width Of Rectangle : \n";
        cin>>width;
        cout<<"Enter A symbol :\n";
        cin>>symbol;
        cout<<"1:-filled Rectange\n2:-for Filled :\n";
        cin>>type;

        if(type==1){
            for(int i=1;i<=height;i++){
                for(int j=1;j<=width;j++){
                    cout<<symbol;
                }
                cout<<"\n";
            }
            cout<<"DO you want more";
            cin>>choice;
        }


    }while(choice!='n');

    return 0;
}