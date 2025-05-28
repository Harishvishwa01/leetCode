
/*
   author : harish vishwa
   Date   : 28 / 5 / 25
*/

#include<bits/stdc++.h>
using namespace std;
class Solution2 {
public:
    int largestAreaOnHistogram(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int maxi = 0;
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || arr[i] < arr[st.top()])) {
                int height = arr[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxi = max(maxi, height * width);
            }
            st.push(i);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;
        vector<int> dp(m, 0);
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                dp[j] = (matrix[i][j] == '1') ? dp[j] + 1 : 0;
            }
            maxi = max(maxi, largestAreaOnHistogram(dp));
        }

        return maxi;
    }
};
