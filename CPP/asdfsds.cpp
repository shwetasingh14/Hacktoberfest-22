#include<bits/stdc++.h>
#include<string>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#define ll long long
#define repi(i,a,b) for(ll i=a;i<=b;i++)
#define repd(i,a,b) for(ll i=a;i>=b;i--)
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define MOD 1000000007
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define nl cout<<"\n"
#define cm cout<<"-1\n"
using namespace std;

int main(){
    ll t=1;
    cin>>t;
    while(t--){
       ll n;
       cin>>n;
       if(n==1) cout<<0<<endl;
       else{
           
       ll x=n/2;
       ll res=0;
       ll ans=0;
       while(x>0){
           res=4*(n-1);
           ans=ans+(x*res);
           n=n-2;
           x=x-1;
       }
       cout<<ans; nl;
       }
    }
    return 0;
}