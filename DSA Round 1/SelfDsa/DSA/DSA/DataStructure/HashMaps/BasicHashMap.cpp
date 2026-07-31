#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    // insetion
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);
    pair<string, int> pair2("Love", 2);
    m.insert(pair2);
    m["mera"] = 1;
    m["mera"] = 2;

    // searching
    cout << m["mera"] << endl;
    cout << m.at("babbar") << endl;
    // cout << m.at("ali") << endl;
    cout << m["ali"] << endl;
    cout << m["ali"] << endl;
    cout << m.at("ali") << endl;
    // to check presence
    cout<<m.count("bro")<<endl;//zero if no key presetn
    cout<<m.count("babbar")<<endl;
    //how to acces hasmap
    // for(auto val:m)
    // {
    //     cout<<val->first<<endl;
    //     cout<<val->second<<endl;

    // }
    //how to make iterator
    unordered_map<string,int>::iterator it=m.begin();
    while(it!=m.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}