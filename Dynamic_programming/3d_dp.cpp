#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>  
using namespace std;  

int f(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){  
    if (i == n - 1) {  
        return j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2];  
    }  
    if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return -1e9;  
    if (dp[i][j1][j2] != -1) return dp[i][j1][j2];  

    int maxi = INT_MIN;  
    for (int d1 = -1; d1 <= 1; ++d1) {  
        for (int d2 = -1; d2 <= 1; ++d2) {  
            int curr = (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);  
            maxi = max(maxi, curr + f(i + 1, j1 + d1, j2 + d2, n, m, grid, dp));  
        }  
    }  

    return dp[i][j1][j2] = maxi;  
}  

int maximumChocolates(int n, int m, vector<vector<int>>& grid) {  
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));  
   // return f(0, 0, c - 1, r, c, grid, dp); 
   for(int j1 = 0; j1 < m; j1++){
     for(int j2 = 0; j2 < m; j2++){
         dp[n - 1][j1][j2] = j1 == j2 ? grid[n - 1][j1] : grid[n - 1][j1] + grid[n -1][j2];
      }
   }

   


   for(int i = n - 2; i >= 0; i--){
       for(int j1 = 0;j1 < m; j1++){
           for(int j2 = 0; j2 < m; j2++){
           int maxi = -1e9;
        for (int  d1 = -1; d1 <= 1; ++d1) {  
        for (int d2 = -1; d2 <= 1; ++d2) {  
            int curr = (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);  
            curr += (j1 + d1 < 0 || j1 + d1 >= m) || (j2 + d2 < 0 || j2 + d2 >= m) ? -1e9 : dp[i + 1][j1 + d1][j2 + d2];
            maxi = max(maxi,curr);
        }  
    } 
         dp[i][j1][j2] = maxi;
           }
       }
   }
   return dp[0][0][m -1];
}
int main(){

}