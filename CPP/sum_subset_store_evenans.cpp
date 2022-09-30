vector <int> g[N];
int subtree_ct[N];
int even_ct[N];
void dfs(int v,int p){
    subtree_ct[v]+=v;
    if(v%2==0){
        even_ct[v]++;
    }
    for(auto it:g[v]){
        if(v==p) continue;
        dfs(it,v);
        subtree_ct[v]+=subtree_ct[it];
        even_ct[v]+=even_ct[it];
       
    }
 
}
