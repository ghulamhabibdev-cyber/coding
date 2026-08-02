#include <iostream>
using namespace std;

class a{

};
int linearSearch(int arr[],int size,int x)
{
  int ans=-1;
  for(int i=0;i<size;i++)
  {
    if(arr[i]==x)
    {
      ans=i;
      break;
    }
  }
  return ans;
}
int main() {
  int arr[10]={1,2,3,5,5,6,7,8,9,10};
  cout<<linearSearch(arr,10,5);
  

  return 0;
}