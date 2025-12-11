#include <iostream>
using namespace std;

class a{

};
char convertChar(char ch)
{
    char ans=ch-'a'+'A';
    return ans;
}
char convertBig(char ch)
{
    char ans=ch-'A'+'a';
    return ans;
}
int main() {
    char ch;
    cout<<"Eneter a Character\n";
    cin>>ch;
    char ans=convertChar(ch);
    cout<<ans<<endl;
    cout<<convertBig(ans);

    return 0;
}