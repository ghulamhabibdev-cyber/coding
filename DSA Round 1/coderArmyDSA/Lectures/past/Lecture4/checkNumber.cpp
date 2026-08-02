#include <iostream>
using namespace std;

class a{

};
void  checkNo(int n)
{
    if(n>0)
    {
        cout<<"Posistive \n";
    }
    else if(n<0)
    {
        cout<<"Negative \n";
    }
    else{
        cout<<"Zero \n";
    }
}
void checkVowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    {
        cout<<"Vowel\n";
    }
    else{
        cout<<"Consonant\n";
    }
}
int main() {
    int number;
    cout<<"Enter Number \n";
    cin>>number;
    checkNo(number);
    char ch;
    cout<<"Enter a Character \n";
    cin>>ch;
    checkVowel(ch);
    

    return 0;
}