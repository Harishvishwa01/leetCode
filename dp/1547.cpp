

/*
  Author : Harish Vishwa 
  Date : 9 / 12 / 24
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<pair<int,int>,int> memo;
    int f(int i, int j, vector<int>& arr) {  
    if (i > j) return 0;  
    pair<int,int> p = make_pair(i,j);
    if(memo.count(p)) return memo[p];
    int mini = INT_MAX;  
    for (int ind = i; ind <= j; ind++) {  
      int ans = arr[j + 1] - arr[i - 1] +
                  f(i, ind - 1, arr) +
                  f(ind + 1, j, arr);  
        mini = min(mini, ans);  
    }  
    return memo[p] = mini;  
}  

    int minCost(int n, vector<int>& cuts) {

    int m = cuts.size();
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(m + 2,vector<int> (m + 2,0));
    for(int i = m; i >= 1; i--){
        for(int j = i; j <= m; j++){
         //   if (i > j) continue;
           int mini = 1e9;
            for(int k = i; k <= j; k++){
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                mini = min(mini,cost);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][m];
}
};

auto init = [](){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 0;
}();