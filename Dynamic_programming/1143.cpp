#include <bits/stdc++.h> 
using namespace std;
class Solution {
private:
    map<pair<int,int>,int> memo;
   int f(int ind1,int ind2,const string& s1,const string& s2){
       if(ind1 < 0 || ind2 < 0) return 0;
       auto p = make_pair(ind1,ind2);
       if(memo.count(p)) return memo[p];
       if(s1[ind1] == s2[ind2]) {
        memo[p] = 1 + f(ind1 - 1,ind2 - 1,s1,s2);
       }
       else{
         int match = f(ind1 - 1,ind2,s1,s2);
         int nmatch = f(ind1,ind2 - 1,s1,s2);
         memo[p] = max(match,nmatch);
       }
       return memo[p];
   }
public: 
int longestCommonSubsequence(string text1, string text2) {  
        int n = text1.size();  
        int m = text2.size();  
     vector<int> dp(m + 1, 0);
     vector<int> cur(m  + 1, 0);
        for (int i = 1; i <= n; ++i) {  
            for (int j = 1; j <= m; ++j) {  
                if (text1[i - 1] == text2[j - 1]) {  
                    cur[j] = dp[j - 1] + 1;  
                } else {  
                    cur[j] = max(dp[j], cur[j - 1]);  
                }  
            }  
            dp = cur;
        }  
        return dp[m];  
    }  
};