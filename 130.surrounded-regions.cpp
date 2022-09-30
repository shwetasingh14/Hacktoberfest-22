/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
private:
    int delRow[4]={-1,0,1,0};
    int delCol[4]={0,1,0,-1};
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, int n, int m) {
        vis[row][col]=1;
        for(int i=0;i<4;i++) {
            int r=row+delRow[i];
            int c=col+delCol[i];

            if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and board[r][c]=='O') {
                dfs(r,c,board,vis,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int j=0;j<m;j++) {
            if(!vis[0][j] and board[0][j]=='O') {
                dfs(0,j,board,vis,n,m);
            }
            if(!vis[n-1][j] and board[n-1][j]=='O') {
                dfs(n-1,j,board,vis,n,m);
            }
        }

        for(int i=0;i<n;i++) {
            if(!vis[i][0] and board[i][0]=='O') {
                dfs(i,0,board,vis,n,m);
            }

            if(!vis[i][m-1] and board[i][m-1]=='O') {
                dfs(i,m-1,board,vis,n,m);
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]=='O' and !vis[i][j]) {
                    board[i][j]='X';
                }
            }
        }
    }
};
// @lc code=end

