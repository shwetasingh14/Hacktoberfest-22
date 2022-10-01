/* Jai Shree Krishna */

#include<bits/stdc++.h>
using namespace std;

int INF = 1000000005;
long long inf = 1000000000000000005LL;
#define sqr(x)                               ((ll)(x) * (x))
#define watch(x)                             cout<<#x<<" : "<<x<<endl
#define all(x)                               x.begin(), x.end()
#define len(v)                               v.size()
#define srt(v)                               sort( v.begin(), v.end())
#define rsrt(v)                              sort( v.rbegin(), v.rend())
#define rvrs(v)                              reverse( v.begin(), v.end())
#define rep(i, a, n)                         for(long long i = a; i < n; i++)
#define pb                                   push_back
#define out(x)                               cout<<x<<"\n";
#define endl                                 "\n"
#define outs(x)                              cout<<x<<" "
#define fastio                               ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long                            ll;
typedef pair<long long, long long>           pl;
typedef pair<long long, pl>                  ppl;
typedef vector<int>                          vi;
typedef vector<long long>                    vl;
typedef vector<vector<long long>>            vvl;
typedef vector<pair<long long, long long>>   vll;
typedef vector<ppl>                          vlll;
typedef vector<string>                       vs;
ll mod = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cout << #x<<" "; _print(x); cout << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.first); cout << ","; _print(p.second); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

//    to_string() : int to string
//    stoi() : string to int
//    stol() , stoll() : string to long and long long resp
#define ppc               __builtin_popcount // returns the number of set bits in a number
#define ppcll             __builtin_popcountll // thus if set bits == 1 then it is a power of 2

void solve(){
    int n , k;
    cin>>n>>k;
    string s;
    cin>>s ;
    while(k--){
        reverse(s.begin(),s.begin() + k + 1);
        // debug(s);
    }
    cout << s << endl;
}

int main(){
    fastio;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
