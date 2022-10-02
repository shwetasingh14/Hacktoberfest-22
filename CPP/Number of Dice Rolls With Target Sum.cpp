
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int numRollsToTarget(int n, int k, int t) {
        int mod = 1e9+7;
        vector<vector<long>> dp(t+1, vector<long> (n+1));
        
        dp[0][0] = 1;
        
        for(int i=1;i<=t;i++){
            for(int j=1;j<=n;j++){
                
                for(int r=1;i-r>=0 && r<=k;r++)
                    dp[i][j] += dp[i-r][j-1];
                
                dp[i][j] %= mod;
            }
        }
        
        return (int)dp[t][n];
}

int main(){

	int n, k, t;

	//n: number of dices
	//k:number of faces
	//t:target sum

	cin >> n >> k >> t;

	return numRollsToTarget(n, k, t);

}
