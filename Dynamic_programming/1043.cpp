#include<bits/stdc++.h>
using namespace std;

/*
   Author : Harish vishwa 
   Date : 22/12/24 
*/
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1,0);
        for(int i = n - 1; i >= 0; i--){
              int maxi = INT_MIN;
              int ans = INT_MIN;
              int len = 0;
              for(int j = i; j < min(n,i + k); j++){
                  len++;
                  maxi = max(maxi,arr[j]);
                  int val = len * maxi + dp[j + 1];
                  ans = max(ans,val);
              }
              dp[i] = ans;
        }
        return dp[0];
    }
};

auto init = [](){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return 0;
}();