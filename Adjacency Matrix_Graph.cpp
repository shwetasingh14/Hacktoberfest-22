//************************** it's all about practice ***********************
#include<bits/stdc++.h>
using namespace std;
//**** Abbreviation ****
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
//**** STL ****
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define ALL(x) x.begin(), x.end()
//**** some I/O ****
#define no         cout << "NO\n"
#define yes        cout << "YES\n"
//**** Fast I/O ****
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//**** Short Code ****
#define tc ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
/*---------------------------------------------------------------------------*/
vector<vector<int>> addEdge(vector<vector<int>> &graph,ll v1,ll v2)
{
   graph[v1-1][v2-1]=1;
   graph[v2-1][v1-1]=1;
   return graph;
}
vector<vector<int>> graph(ll v,ll e)
{
   vector<vector<int>> gr;
   gr.reserve(v);
   f(i,0,v)
   {
       vector<int> temp;
       temp.reserve(v);
       f(j,0,v)
           temp.pb(0);
       gr.pb(temp);
   }
   f(i,0,e)
   {
       int v1,v2;
       cin>>v1>>v2;
       gr=addEdge(gr,v1,v2);
   }
   return gr;
}
void print(vector<vector<int>> &graph,ll v,ll e)
{
   f(i,0,v)
   {
       f(j,0,graph[i].size())
       {
           cout<<graph[i][j]<<" ";
       }
       cout<<"\n";
   }
}
int main()
{
   FAST_IO
   ll v,e;// number of vertices and number of edges
   cin>>v>>e;
   vector<vector<int>> gr=graph(v,e);
   print(gr,v,e);
   return 0;
}
