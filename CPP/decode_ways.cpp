class Solution {
    int sumWays(vector<vector<int>> &dp,string s,int i,int j,int n){
        if(i>=n || j>=n) return 0;
        if(s[i]=='0') return 0;
        if(j-i>1) return 0;
        if(j-i==1 && (s[i]>'2' || (s[i]=='2' && s[j]>'6'))) return 0;
        if(j==n-1) return 1;
        if(dp[i][j-i]!=-1) return dp[i][j-i];
        return dp[i][j-i]=sumWays(dp,s,i,j+1,n)+sumWays(dp,s,j+1,j+1,n);
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return sumWays(dp,s,0,0,n);
    }
};