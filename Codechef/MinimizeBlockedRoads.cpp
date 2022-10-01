/*
    AUTHOR - PRACHHI SABITA MISHRA
*/
#include<bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define ld long double
#define MOD 1000000007
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
using namespace std;
ll add(int x, int y) {int res=x+y; return(res>=MOD?res-MOD:res);}
ll mul(int x, int y) {int res=x*y; return(res>=MOD?res%MOD:res);}
ll sub(int x, int y) {int res=x-y; return(res<0?res+MOD:res);}
ll lcm(int x, int y) {int res=(x*y)/__gcd(x,y); return res;}
ll power(int x,int y) {int res=1; x%=MOD; while(y){if(y&1)res=mul(res,x); y>>=1; x=mul(x,x);} return res;}
ll min(int a, int b) { return (a < b) ? a : b; }


int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastio;
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        k=n-k;
        vector<vector<ll>> g(n+1);
        set<pair<ll, ll>> b;
        for(ll i=0;i<n-1;i++){
            int u,v,x;
            cin>>u>>v>>x;
            if(x)
                b.insert({min(u, v), max(u, v)});
            g[u].push_back(v);
            g[v].push_back(u);
        }
    vector<ll> ss(n+1);
    auto d1=[&](ll u,ll par, const auto &d1) -> void
    {
        ss[u] = 1;
        for(auto v: g[u]){
            if(v!=par){
                d1(v, u, d1);
                ss[u] += ss[v];
            }
        }
    };
    d1(1, 0, d1);
    multiset<ll, greater<ll>>tr;

    auto d2 = [&](ll u,ll par,const auto &d2) -> void
    {
        for(auto v:g[u]){
            if(v!=par){
                if(b.find({min(u, v), max(u, v)}) != b.end())
                    tr.insert(ss[v]);
                else
                    d2(v, u, d2);
            }
        }
    };
    d2(1,0,d2);
    ll ans=0;
    for(auto x:tr){
        if(k<=0)
            break;
        k -= x;
        ans++;
    }
    if(k>0)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    }
    return 0;
}