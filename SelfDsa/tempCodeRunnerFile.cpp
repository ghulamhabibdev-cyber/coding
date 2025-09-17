#include <bits/stdc++.h>
using namespace std;
int getSumOfLastFirstDigit(int number)
{
    int sum=0;
    sum+=number%10;
    while(number>10)
    {
        number=number/10;
    }
    sum+=number;
    return sum;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int number;
	    cin>>number;
        int ans=getSumOfLastFirstDigit(number);
        cout<<ans<<endl;
	}

}
