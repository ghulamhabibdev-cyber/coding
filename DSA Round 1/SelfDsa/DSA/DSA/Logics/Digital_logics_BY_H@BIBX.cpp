#include<iostream>
using namespace std;
void Decorator()
{
    cout<<">|==========================================================================|<\n";
}
bool ANDGATE(bool Input1,bool Input2)
{ 
    return Input1&&Input2;
}
bool ORGATE(bool Input1,bool Input2)
{
    return Input1||Input2; 
}
bool NOTGATE(bool Input)
{
    return !Input;
}
bool NANDGATE(bool Input1,bool Input2)
{
        return NOTGATE(ANDGATE (Input1,Input2));
}
bool NORGATE(bool Input1,bool Input2)
{
    return  NOTGATE(ORGATE(Input1, Input2));
}
bool XORGATE(bool Input1,bool Input2)
{
    return ORGATE(ANDGATE(!Input1,Input2),ANDGATE(Input1,!Input2));
}
bool XNORGATE(bool Input1,bool Input2)
{
    return ORGATE(ANDGATE(!Input1,!Input2),ANDGATE(Input1,Input2));
}
bool ANDGATE_Using_NANDGATE(bool Input1,bool Input2)
{
    return NANDGATE(NANDGATE(Input1,Input2),NANDGATE(Input1,Input2));
}
bool NOT_USING_NAND(bool Input1)
{
    return NANDGATE(Input1,Input1);

}
bool OR_USING_NAND(bool Input1,bool Input2)
{
    return NANDGATE(NANDGATE(Input1,Input1),NANDGATE(Input2,Input2));
}
bool NOTGATE_USING_NORGATE(bool Input1)
{
    return NORGATE(Input1,Input1);
}
bool ANDGATE_USING_NORGATE(bool Input1,bool Input2)
{
    return NORGATE(NORGATE(Input1,Input1),NORGATE(Input2,Input2));
}
bool ORGATE_UISNG_NORGATE(bool Input1,bool Input2)
{
    return NORGATE(NORGATE(Input1,Input2),NORGATE(Input1,Input2));
}
int main()
{
    bool input1;
    bool input2;
    int num;
    string choice;
//    do{
    
//     cout<<"Press n to EXIT\ny to agian\n";
//     getline(cin,choice);
//     cout<<"Enter 0 OR 1 : (input must be 1 OR 0)\n";
//     cin>> input1;
//     cin.ignore();
//     cout<<"Enter Another OR 1 : (input must be 1 OR 0)\n";
//     cin>> input2;
//     cin.ignore();
//     cout<<"ANDGATE OutPut            :  "<<ANDGATE(input1,input2)<<endl;
//     Decorator();
//     cout<<"ORGATE OutPut             :  "<<ORGATE(input1,input2)<<endl;
//     Decorator();

//     cout<<"NOTGATE OutPut    of input1        :  "<< NOTGATE(input1)<<endl;
//      Decorator();
//     cout<<"NOTGATE OutPut    of input2      :  "<< NOTGATE(input2)<<endl;
//     Decorator();
//     cout<<"NANDGATE OutPut           :  "<< NANDGATE(input1,input2)<<endl;
//     Decorator();
//     cout<<"NORGATE OutPut            :  "<<NORGATE(input1,input2)<<endl;
//     Decorator();
//     cout<<"XORGATE OutPut            :  "<<XORGATE(input1,input2)<<endl;
//     Decorator();
//     cout<<"XNORGATE OutPut            :  "<<XNORGATE(input1,input2)<<endl;
//     Decorator();
//     cout<<"ANDGATE_Using_NANDGATE: " <<ANDGATE_Using_NANDGATE(input1,input2)<<endl;
//     Decorator();
//     cout<<"<NOT_USING_NAND of(input1): " <<NOT_USING_NAND(input1)<<endl;
//     cout<<"<NOT_USING_NAND of(input2): " <<NOT_USING_NAND(input2)<<endl;
//     Decorator();
//     cout<<"OR_USING_NAND : " <<OR_USING_NAND(input1,input2)<<endl;
//     Decorator();
//     cout<<"NOTGATE_USING_NORGATE (input1): " <<NOTGATE_USING_NORGATE(input1)<<endl;
//     Decorator();
//     cout<<"NOTGATE_USING_NORGATE (input2): " <<NOTGATE_USING_NORGATE(input2)<<endl;
//     Decorator();
//     cout<<"ANDGATE_USING_NORGATE: " <<ANDGATE_USING_NORGATE(input1,input2)<<endl;
//     Decorator();
//     cout<<"ORGATE_UISNG_NORGATE: " <<ORGATE_UISNG_NORGATE(input1,input2)<<endl;
//     Decorator();
//    }while(choice!="y");
       bool carry= XNORGATE(1,1);
       cout<<carry<<endl;
       bool sum=XNORGATE(carry,1);
       cout<<sum<<endl;
       bool car2=(carry,0);   
    
    
       
}