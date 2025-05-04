 #include<bits/stdc++.h>
using namespace std;
class Solution {

public:
   
    void dfs(int row, int col, vector<vector<char>>& mat,
             vector<vector<int>>& vis,int delRow[],int delCol[]) {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and
                !vis[nrow][ncol] and mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, mat, vis,delRow,delCol);
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
         int delRow[] = {1, -1, 0, 0};
         int delCol[] = {0, 0, -1, 1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            if (!vis[0][i] && mat[0][i] == 'O') {
                dfs(0, i, mat, vis,delRow,delCol);
            }
            if (!vis[n - 1][i] && mat[n - 1][i] == 'O') {
                dfs(n - 1, i, mat, vis,delRow,delCol);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, mat, vis,delRow,delCol);
            }
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O') {
                dfs(i, m - 1, mat, vis,delRow,delCol);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0;j < m; j++){
                if(!vis[i][j] && mat[i][j] == 'O') 
                    mat[i][j] = 'X';
            }
        }
    }
};