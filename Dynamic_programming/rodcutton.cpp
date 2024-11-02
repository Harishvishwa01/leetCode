#include <bits/stdc++.h>
using namespace std;
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<int, int>, int,hash_pair> memo;
int f(int ind, int w, vector<int>& price){
    if (ind == 0) {
        return (w / (ind + 1)) * price[0];
    }
    pair<int, int> p = make_pair(ind, w);
    if (memo.count(p)) return memo[p];
    int ntake = f(ind - 1, w, price);
    int take = (ind + 1 <= w) ? price[ind] + f(ind, w - (ind + 1), price) : -1e9;
    return memo[p] = max(ntake, take);
}

int cutRod(vector<int>& price, int n) {
 vector<int> dp(n + 1,0);


    for(int i = 0; i< n; i++){
        for(int j = i + 1;  j<=n; j++){
           
            dp[j] = max(dp[j],price[i] + dp[j - (i + 1)]);
        }

    }
    return dp[n];
  
  
}


