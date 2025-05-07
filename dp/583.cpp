#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> dp(m + 1, 0),cur(m + 1, 0);
        int maxi = INT_MIN;
        for(int i = 1; i <= n; i++){
            for(int j = 1;  j <= m; j++){
                if(s1[i  - 1] == s2[j - 1]){
                     cur[j] = 1 + dp[j - 1];
                }
                else{
                    cur[j] = max(dp[j], cur[j -1]);
                }
                   maxi = max(maxi,cur[j]);
            }
            dp = cur;
        }
        return (n + m) - (2 * maxi); 
    }
};