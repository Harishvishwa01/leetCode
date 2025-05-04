#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum & 1)
            return 0;
        int k = sum >> 1;
        vector<bool> dp(k + 1, false);
        dp[0] = true;
        if(nums[0] <= k){
            dp[nums[0]] = true;
        }

        for(int i = 1; i < n; i++){
            vector<bool> cur(k + 1,0);
            cur[0] = true;
            for(int j = 1; j <= k ;j ++){
               bool npick = dp[j];
               bool pick = false;
               if(j >= nums[i]) pick = dp[j - nums[i]];
               cur[j] = pick || npick;
            }
            dp = cur;
        }

        return dp[k];
    }
};



int main(){

}