
#include <bits/stdc++.h>
using namespace std;  


typedef long long ll;
const ll mod = 1e9 + 7;

class Solution {
public:
    vector<int> findNextSmallerIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> findPreSmallerIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1); 
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNextSmallerIndex(arr);
        vector<int> pse = findPreSmallerIndex(arr);

        ll total = 0;
        for (int i = 0; i < n; i++) {
            ll left = i - pse[i];
            ll right = nse[i] - i;
            total = (total + arr[i] * left % mod * right % mod) % mod;
        }
        return (int)total;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
