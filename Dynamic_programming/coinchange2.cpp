#include<bits/stdc++.h>
using namespace std;
class Solution {  
public:  
 int f(int ind,vector<int>& nums, int tar, vector<vector<int>>&dp){  
        if (tar == 0) return 1;  
        if (ind == 0) return (tar % nums[ind] == 0);  
        if (dp[ind][tar] != -1) return dp[ind][tar];  
        int ntake = f(ind - 1, nums, tar, dp); 
        int take = 0;  
        if (tar >= nums[ind])  
            take = f(ind, nums, tar - nums[ind], dp);  

        return dp[ind][tar] = take + ntake;  
    }  

 int change(int T, vector<int>& arr) {  
    int n = arr.size();  
    vector<uint64_t> dp(T + 1, 0);  
     dp[0] = 1;
        for(int i = 0; i <= T / arr[0]; i++){
            dp[i * arr[0]] = 1;
        } 
    for (int i = 1; i < n; ++i) {  
        for (int j = arr[i]; j <= T; ++j) {  
            dp[j] += dp[j - arr[i]];  
        }  
    }  

    return dp[T];  
}  
};