#include <bits/stdc++.h>
using namespace std;
void RepeatedOrder(){
    int arr[10]={ 1, 2, 5, 4, 4, 2, 5, 1, 2, 9 };
    for(int i=0;i<10;i++){
        bool Repeat=false;

        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                Repeat=true;
                break;  
            }

            
            
        }
        if(Repeat==true){
            continue;
        }
            for(int k=i+1;k<10;k++){
                if(arr[i]==arr[k]){
                    cout<<arr[i]<<" at Index "<<i<<endl;
                    break;
                }
            }
        }
    }

int main()
{
    RepeatedOrder();
}