#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<int> dp(n + 1, 0), cur(n + 1, 0);
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    cur[j] = 1 + dp[j - 1];

                } else {
                    cur[j] = max(dp[j], cur[j - 1]);
                }
                maxi = max(maxi, cur[j]);
            }
            dp = cur;
        }
        return n - maxi;
    }
};

int init = []() {  
    std::ios::sync_with_stdio(false);  
    std::cin.tie(nullptr);  
    std::cout.tie(nullptr);  
    return 0;  
}();