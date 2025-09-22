#include<bits/stdc++.h>
using namespace std;
class  a
{

};

int main()
{
    vector<int>v;
    for(int i=0;i<3;i++)
    {
        int num;
        cout<<"Enter the number\n";
        cin>>num;
        v.push_back(num);
    }
    // cout<<"Print data using simple iterator and copy func\n";
    // vector<int>::iterator intvec;
    // for(intvec=v.begin();intvec!=v.end();intvec++)
    // {
    //     cout<<*intvec<<", ";
    // }

    // vector<int>::iterator vBeg=v.begin();
    // vector<int>::iterator vEnd=v.end();
    // ostream_iterator<int>screen(cout,", ");
    // cout<<endl;
    // cout<<"End\n";
    // cout<<"printing the thing using screen and iterator for vector then for other d.s\n";
    // copy(vBeg,vEnd,screen);
    vector<int>::iterator intvec=v.begin();
    intvec++;
    v.insert(intvec,22);
    // insert take pos and elem
    v.insert(intvec,10,6);
    ostream_iterator<int> screen(cout,", ");
    vector<int> extra = {100, 200, 300};
    intvec = v.begin();
    intvec++;
    v.insert(intvec,extra.begin(),extra.end());

    copy(v.begin(),v.end(),screen);
    


    return 0;
}
