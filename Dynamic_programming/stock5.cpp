#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    map<pair<int,int>,int> memo;
    int f(int ind,int buy,int fee,vector<int>& arr){
        if(ind >= arr.size()) return 0;
        pair<int,int> p = make_pair(ind,buy);
        if(memo.count(p)) return memo[p]; 
         if(buy == 1){
           return memo[p] = max(-arr[ind] + f(ind + 1,0,fee,arr), f(ind + 1,1,fee,arr));
         }
         else{
            return memo[p] = max(arr[ind] - fee + f(ind + 1,1,fee,arr), f(ind+1,0,fee,arr));
         }
    }
      int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
       
        vector<int> dp(2, 0), cur(2, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                if (j == 1) {
                    cur[j] = max(-prices[i] + dp[0], dp[1]);
                } else {
                    cur[j] = max(prices[i] - fee + dp[1], dp[0]);
                }
            }
            
            dp = cur;
        }
      return dp[1];
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();