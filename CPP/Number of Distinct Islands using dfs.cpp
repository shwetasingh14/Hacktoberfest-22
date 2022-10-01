#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void dfs(vector<vector<int>>& grid, int i, int j, string& s){
        int r=grid.size(), c=grid[0].size();
        if(i<0 || i>=r || j<0 || j>=c || grid[i][j]!=1) return;
        
        grid[i][j]=2;
        
        s.push_back('d');
        dfs(grid, i+1, j, s);
        
        s.push_back('u');
        dfs(grid, i-1, j, s);
        
        s.push_back('r');
        dfs(grid, i, j+1, s);
        
        s.push_back('l');
        dfs(grid, i, j-1, s);
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int r=grid.size(), c=grid[0].size();
        map<string, int> mp;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    string s;
                    dfs(grid, i, j, s);
                    mp[s]++;
                }
            }
        }
        
        return mp.size();
    }
};


int main(){
    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));

    for(int i=0;i<r;i++){
        for(int j=0;i<c;j++){
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.countDistinctIslands(grid);
}
