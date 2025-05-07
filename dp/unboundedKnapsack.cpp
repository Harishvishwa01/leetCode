
#include<bits/stdc++.h>
using namespace std;
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt) {  
    vector<int> dp(w + 1, 0);  

    for (int i = 0; i < n; i++) {  
        for (int j = wt[i]; j <= w; j++) { 
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]); 
        }  
    }  
    return dp[w];  
}