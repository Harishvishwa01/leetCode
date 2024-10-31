#include <bits/stdc++.h> 
using namespace std;
int f(int ind, vector<int>& w, vector<int>& val, vector<vector<int>>& dp, int W){

  if (ind == 0) {
	  if(W >= w[ind]) return val[ind];
    return 0;
  }
        if(dp[ind][W] != -1) return dp[ind][W];
	int ntake = f(ind - 1, w,val,dp,W);
	int take = (W >= w[ind]) ? val[ind] + f(ind - 1, w,val,dp,W - w[ind]) : 0;
	return dp[ind][W] = max(take, ntake);
}
int knapsack(vector<int>& wt, vector<int>& val, int n, int w) {  
    vector<int> dp(w + 1, 0);  

    for (int i = 0; i < n; i++) {  
        for (int j = w; j >= wt[i]; j--) {   
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);   
        }  
    }  
    return dp[w];  
}
