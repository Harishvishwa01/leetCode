
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<pair<int, int>, int> dp;
    int f(vector<int>& nums, int ind, int tar) {
        if (ind == 0)
            return tar == 0 ? 1 : 0;
        pair<int, int> p = make_pair(ind, tar);
        if (dp.count(p))
            return dp[p];
        return dp[p] = f(nums, ind - 1, tar + nums[ind - 1]) +
                       f(nums, ind - 1, tar - nums[ind - 1]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;

        for (auto it : nums)
            total += it;

        if ((total - target) % 2 != 0 || total < abs(target))
            return 0;

        int sum = (total - target) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int ind = 1; ind <= n; ind++) {
            for (int j = 0; j <= sum; j++) {
                int notPick = dp[ind - 1][j];
                int pick = 0;

                if (j >= nums[ind - 1]) {
                    pick = dp[ind - 1][j - nums[ind - 1]];
                }

                dp[ind][j] = pick + notPick;
            }
        }

        return dp[n][sum];
    }
};