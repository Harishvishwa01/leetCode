#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int day, int buy, int cap, vector<int>& prices,
          vector<vector<vector<int>>>& dp) {
        if (day == prices.size() || cap == 0)
            return 0;
        if (dp[day][buy][cap] != -1)
            return dp[day][buy][cap];

       if (buy == 1) {
            return dp[day][buy][cap] =
                       max(-prices[day] + f(day + 1, 0, cap, prices, dp),
                           f(day + 1, 1, cap, prices, dp));
        } else {
            return dp[day][buy][cap] =
                       max(prices[day] + f(day + 1, 1, cap - 1, prices, dp),
                           f(day + 1, 0, cap, prices, dp));
        }
    }

   int maxProfit(int k, vector<int>& prices) {  
    int n = prices.size();
    //vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(2 ,vector<int> (k + 1, 0)));

    vector<vector<int>> dp(2,vector<int> (k + 1,0)),cur(2,vector<int> (k + 1,0));
     for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                     if (buy == 0) { 
                    cur[buy][cap] = max(0 + dp[0][cap],-prices[ind] + dp[1][cap]);
                }

                if (buy == 1) { 
                    cur[buy][cap] = max(0 + dp[1][cap], prices[ind] + dp[0][cap - 1]);
                }
                   
                }
            }
            dp = cur;
        }
   
    
    return dp[0][k];
   }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();