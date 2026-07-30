#include <iostream>
#include<vector>
using namespace std;

class a{

};
vector<int> reverseArray(vector<int>v)
{
  int i=0;
  int j=v.size()-1;
  while(i<j)
  {
    swap(v[i],v[j]);
    i++;
    j--;
  }
  return v;
}
void printArray(vector<int>v)
{
   int j=v.size();
  for(int i=0;i<j;i++ )
  {
    cout<<v[i]<<" ";
  }
}
int main() {
  vector<int>v={1,2,3,4,5,6,7,8};
 v= reverseArray(v);
 printArray(v);

  return 0;
}