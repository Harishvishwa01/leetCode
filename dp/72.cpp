#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<pair<int, int>, int> memo;
    int f(int i, int j, string& s1, string& s2) {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        pair<int, int> p = make_pair(i, j);
        if (memo.count(p))
            return memo[p];
        if (s1[i] == s2[j]) {
            return memo[p] = f(i - 1, j - 1, s1, s2);
        } else {
            return memo[p] = 1 + min(f(i - 1, j, s1, s2),
                                     min(f(i, j - 1, s1, s2),
                                         f(i - 1, j - 1, s1, s2)));
        }
    }
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        // return f(n - 1, m - 1, s1, s2);
        //vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        vector<int> dp(m + 1, 0), cur(m + 1, 0);
        for (int j = 0; j <= m; j++) {
            dp[j] = j;
        }
        for (int i = 1; i <= n; i++) {
            cur[0] = i;
             for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    cur[j] = dp[j - 1];
                } else {
                    cur[j] = 1 + min(dp[j], min(cur[j - 1], dp[j - 1]));
                }
            }
            dp = cur;
        }
        return dp[m];
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();