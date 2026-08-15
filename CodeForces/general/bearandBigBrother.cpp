#include <iostream>
using namespace std;

class A
{
};
int makeLimakHearveri(int bobWeight, int limakWeight)
{
    int count=0;
    while(limakWeight<=bobWeight)
    {
        limakWeight*=3;
        bobWeight*=2;
        count++;
    }
    return count;
}

    int
    main()
{
    int limakWeight;
    int bobWeight;
    cin>>limakWeight;
    cin>>bobWeight;
    int afterYears=makeLimakHearveri(bobWeight,limakWeight);
    cout<<afterYears<<endl;

    return 0;
}