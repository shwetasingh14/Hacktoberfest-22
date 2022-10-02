
    int t[1002][1002];
    
    int solve(int w, int wt[], int val[], int n){
        if(n==0 || w==0) return 0;
        
        if(t[n][w]!=-1) return t[n][w];
        
        if(wt[n-1]<=w)
            return t[n][w] = max(val[n-1]+solve(w-wt[n-1], wt, val, n-1), solve(w, wt, val, n-1));
            
        else if(wt[n-1]>w)
            return t[n][w] = solve(w, wt, val, n-1);
    }

    int main(){
        int n, w;
        cin >> n >> w;
        int wt[n], val[n];
      
        memset(t, -1, sizeof(t));
      
        for(int i=0;i<n;i++)
            cin >> wt[i];
      
        for(int i=0;i<n;i++)
            cin >> val[i];
      
        return solve(w, wt, val, n);
    }
