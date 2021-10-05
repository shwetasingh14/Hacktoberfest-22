//Given An Array of size n,we need to find the first repeating Element.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter No. Of elements in Array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int t=1e6+1;
    int idx[t];
    for(int i=0;i<t;i++)
    {
        idx[i]=-1;
    }
    int minindx=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(idx[arr[i]]!=-1)
        {
            minindx=min(minindx,idx[arr[i]]);
        }
        else
        {
            idx[arr[i]]=i;
        }
    }
    if(minindx==INT_MAX)
    {
        cout<<"No Element Appeared Twice.";
    }
    else
    {
        cout<<"At Index "<<minindx<<" Position "<<minindx+1<<".";
    }
    return 0;
}
