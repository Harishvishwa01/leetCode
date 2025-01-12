/*
  Author : "Harish Vishwa"
  Date : "12 / 1 /25" 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& arr){
      vis[row][col] = 1;
      int n = arr.size();
      int m = arr[0].size();
      for(int i = -1; i <= 1; i++){
          for(int j = -1; j <= 1; j++){
               int nrow = row + i;
               int ncol = col + j;
               if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and arr[nrow][ncol] == 1){
                   dfs(nrow,ncol,vis,arr);
               }
          }
      }
  }
  int solve(vector<vector<int>>& arr){
      int n = arr.size();
      int m = arr[0].size();
      vector<vector<int>> vis(n,vector<int>(m,0));
      int cnt = 0;
      for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
              if(!vis[i][j] and arr[i][j] == 1){
                  cnt++;
                  dfs(i,j,vis,arr);
              }
          }
      }
      return cnt;
  }
};

int main() {
    Solution o;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (auto& i : arr) {
        for (auto& j : i) {
            cin >> j;
        }
    }
    cout << o.solve(arr) << endl;
    return 0;
}
