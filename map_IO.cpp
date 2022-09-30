#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v={2,4,1,5,7};
    map<int,int> m;
    for(int i=0;i<v.size();i++)
    {
        m.insert({v[i],i});
    }
    cout<<endl;
    for(auto n : m)
    {
        cout<<n.first<<" "<<n.second;
        cout<<endl;
    }
    return 0;
}