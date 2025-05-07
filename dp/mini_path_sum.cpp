
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
       vector<vector<int>> dp(n,vector<int>(m,0));
       for(int i = 0; i < m; i ++){
        dp[0][i]  = matrix[0][i];
       } 

      for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            int up = dp[i - 1][j];
            int left = (j -1 >= 0) ? dp[i - 1][j - 1] : INT_MAX;
            int right = (j + 1 < m) ? dp[i - 1][j + 1] : INT_MAX;

        dp[i][j] = matrix[i][j] + min(up,min(left,right));
        }
      }
       int minPathSum = INT_MAX;  
        for (int j = 0; j < m; j++) {  
            minPathSum = min(minPathSum, dp[n - 1][j]);  
        }  

        return minPathSum;
    }
};

int main(){
    
}