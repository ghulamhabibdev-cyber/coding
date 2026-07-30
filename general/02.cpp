#include <iostream>

using namespace std;
bool noOfProblemSolved(int arr[],int size)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==1)
        {
            count++;
        }
    }
    return count>=2;
}
int main() {
    int n;
    cin>>n;
   
    int count=0;
   while(n!=0)
   {
     int teamVotes[3];
        for(int i=0;i<3;i++)
        {
            cin>>teamVotes[i];
        }
        bool isSolved=noOfProblemSolved(teamVotes,3);
        if(isSolved)
        {
            count++;
        }
        n--;
   }
   cout<<count;
  

    
    return 0;
}