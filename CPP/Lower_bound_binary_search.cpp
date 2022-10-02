#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t=1;
  while (t--) {
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
      cin>>arr[i];
    }
    sort(arr,arr+n);
    ll target;
    cin>>target;
    ll lo=0,hi=n-1;
    while(hi-lo>1){
      if(arr[(hi+lo)/2]>=target)
      hi=(lo+hi)/2;
      else
      lo=(hi+lo)/2+1;
    }
    if(arr[lo]>=target)
    cout<<"Lower bound of target is "<<arr[lo]<<endl;
    else if(arr[hi]>=target)
    cout<<"Lower bound of target is "<<arr[hi]<<endl;
    else
    cout<<"Lower bound of target does not exist"<<endl;
  }
  return 0;
}