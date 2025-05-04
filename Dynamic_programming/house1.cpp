#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int ind, vector<int>& nums,vector<int>& dp){
      //  if(ind == 0) return dp[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + solve(ind - 2,nums,dp);
        int dpick = solve(ind -1,nums,dp);

        return dp[ind] = max(pick,dpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0) return 0;
        if(n == 1) return nums[0];
        
       int prev = nums[0];
       int prev2 = 0;

        for(int i = 1; i < n; i++){
            int pick =  nums[i] + prev2;
            int dpick = prev;

            int curi = max(dpick,pick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
        
         
    }
};

int main(){
   
}