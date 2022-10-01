#include<bits/stdc++.h>
using namespace std;

int INF = 1000000005;
long long INFF = 1000000000000000005LL;
#define sqr(x) ((ll)(x) * (x))
#define watch(x) cout<<#x<<" : "<<x<<endl
#define all(x) x.begin(), x.end()
#define len(v) v.size()
#define srt(v) sort( v.begin(), v.end())
#define rsrt(v) sort( v.rbegin(), v.rend())
#define rvrs(v) reverse( v.begin(), v.end())
#define rep(i, a, n) for(long long i = a; i < n; i++)
#define rep0(i, n) for(long long i = 0; i < n; i++)
#define rep1(i, n) for(long long i = 1; i <= n; i++)
#define repn(i, n) for(long long i = n-1;i >= 0;i--)
#define repstl(i,v) for(auto &i: v)
#define pb push_back
#define out(x) cout<<x<<"\n";
#define endl "\n"
#define outs(x) cout<<x<<" "
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef pair<long long, long long> pl;
typedef pair<long long, pl> ppl;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<pair<long long, long long>> vll;
typedef vector<ppl> vlll;
typedef vector<string> vs;
ll mod = 1e9 + 7;

int main(){
    fastio;
    string s;
    cin>>s;
    ll n = s.size();
    ll k;
    cin>>k;
    bool flag = true;
    while(flag){
        ll cnt = 1;
        rep(i,0,n-k+1){
            cnt = 1;
            rep(j,i+1,i+k){
                if(s[j] == s[j-1]){
                    cnt++;
                }
                else cnt = 1;
            }
            if(cnt == k){
                s.erase(i,k);
                break;
            }
            if(i == n-k-1 && cnt < k) flag = false;
        }

    }
    out(s);
    return 0;
}