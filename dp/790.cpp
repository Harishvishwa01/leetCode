#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;
        vector<ll> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i = 4; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] % mod + dp[i - 3]) % mod;
        }
        return dp[n];
    }
};

// 1 2 5 11 24 

auto init = [](){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 0;
}();