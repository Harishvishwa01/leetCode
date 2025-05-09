#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i, int j,int n, vector<vector<int>> & triangle,vector<vector<int>>& dp){
         if(dp[i][j] != -1) return dp[i][j];
        if(i == n - 1) return triangle[i][j];
       
        int up = triangle[i][j] + f(i + 1,j,n,triangle,dp);
        int diag =triangle[i][j] +f(i + 1,j + 1,n,triangle,dp);

        return dp[i][j] = min(up,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n, 0));
        // tabulation 

       for(int j = 0; j < n; j++) dp[n -1][j] = triangle[n - 1][j];

       for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
          int up = triangle[i][j] + dp[i + 1][j];
          int right = triangle[i][j] + dp[i + 1][j + 1];

          dp[i][j] = min(up,right);  
        }
       }
       return dp[0][0];
    }
};

int main(){

}