/* 
   Author : Harish Vishwa
   Date : 19 / 11 / 2024
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
         int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                dp[i] = max(dp[i],1 + dp[j]);
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();