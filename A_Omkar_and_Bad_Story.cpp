#include<bits/stdc++.h>
using namespace std;

int INF = 1000000005;
long long inf = 1000000000000000005LL;
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
vector <ll> primes;
ll modoinv(ll a, ll m)
{
  ll m0 = m;
  ll y = 0, x = 1;
 
  if (m == 1)
    return 0;
 
  while (a > 1) {
 
    ll q = a / m;
    ll t = m;
 
 
    m = a % m, a = t;
    t = y;
 
 
    y = x - q * y;
    x = t;
  }
 
 
  if (x < 0)
    x += m0;
 
  return x;
}
class Graph
{
  map<ll , vector<pair<ll, ll>>> ma;
public:
  void addedge(ll n, ll m, ll k)
  {
    ma[n].pb({m, k});
    ma[m].pb({n, k});
  }
  vector<ll> solve()
  {
    vector<ll> ans;
    sol(ans, 1, 1, 0, 1);
    return ans;
  }
 
  void sol(vector<ll> &ans, ll node, ll count, ll dist, ll parent)
  {
    if ((node != 1) and (ma[node].size() == 1))
    {
      ans.pb(dist);
      return;
    }
    for (auto pp : ma[node])
    {
      ll a = pp.first;
      ll b = pp.second;
      if (a != parent)
      {
        sol(ans, a, count + 1, dist + (count * b), node);
      }
    }
  }
};
class Node
{
public:
  char data;
  unordered_map<char, Node*> children;
  bool terminal;
  Node(char d)
  {
    data = d;
    terminal = false;
  }
};
class Trie
{
public:
  Node* root;
  ll cnt;
  Trie()
  {
    root = new Node('\0');
    cnt = 0;
  }
  void insert(char *w)
  {
    Node* temp = root;
    for (ll i = 0; w[i] != '\0'; i++)
    {
      char ch = w[i];
      if (temp->children.count(ch))
      {
        temp = temp->children[ch];
      }
      else
      {
        Node* n = new Node(ch);
        temp->children[ch] = n;
        temp = n;
      }
    }
    temp->terminal = true;
  }
 
  bool find(string w)
  {
    Node* temp = root;
    for (ll i = 0; w[i] != '\0'; i++)
    {
      char ch = w[i];
      if (temp->children.count(ch) == 0)
        return false;
      else
      {
        temp = temp->children[ch];
      }
    }
    return temp->terminal;
  }
};
vector<ll> primeFactors(ll n)
{
  vector<ll> ans;
  ll cur = 1;
  ans.pb(1);
  while (n % 2 == 0)
  {
    cur = cur * 2;
    ans.pb(cur);
    n = n / 2;
  }
  for (ll i = 3; i * i <= (n); i = i + 2)
  {
    while (n % i == 0)
    {
      cur = cur * i;
      ans.pb(cur);
      n = n / i;
    }
  }
  if (n > 2)
    ans.pb(cur * n);
  return ans;
}
void sieve(ll p)
{
  vector <bool> mark(p, 1);
  for (ll i = 3; i < p; i += 2)
  {
    if (mark[i] == 1)
    {
      for (ll j = i * i ; j < p ; j += 2 * i)
      {
        mark[j] = 0;
      }
    }
  }
  primes.pb(2);
  for (ll i = 3; i < p; i += 2)
  {
    if (mark[i])
      primes.pb(i);
  }
}
ll mod_exp(ll x, ll n, ll m)
{
  //cout << x << " " << n << endl;
  if (n == 0)
    return 1 % m;
  ll a = mod_exp(x, n / 2, m);
  if (n % 2 == 0)
    return (a * a) % m;
  else
    return (x * a * a) % m;
}
bool isPrime(ll n)
{
  if (n == 1)
    return 1;
  if (n == 2)
    return 1;
  for (ll i = 2; i * i <= n; i++)
    if (n % i == 0)
      return 0;
  return 1;
}
 
ll nc2(ll n)
{
  if (n < 2)
    return 0;
  else
    return ((n) * (n - 1)) / 2;
}
//    1. Take care of the corner cases, write one or two tests that seem to be the cases.
//    2. Check the bounds on the intput and decide the algorithm.
//    3. Make the test cases for the bounds, try to include 0, 1, 2 cases in the new test cases, and if possible, scale the cases.
//    4. Check for overflow and the array bounds carefully, always take care of the decreasing loop.

void solve(){
    ll n;
    cin>>n;
    vl a(n);
    bool flag = 0;
    ll mx = 0;
    rep(i,0,n){
        cin>>a[i];
        if(a[i] < 0) flag = true;
        mx = max(mx , a[i]);
    }
    if(flag){
        out("NO");
    }
    else{
        out("YES");
        out(mx+1);
        rep(i,0,mx+1){
            outs(i);
        }
        cout<<endl;
    }
}

int main(){
    fastio;
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
