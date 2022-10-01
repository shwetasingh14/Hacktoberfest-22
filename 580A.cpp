#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ans=1,count=1;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if(a[i]>=a[i-1]){
            count++;
            ans = max(count,ans);
        }
        else
        {
            count = 1;
        }
        
    }
    cout<<ans<<endl;
    return 0;
}