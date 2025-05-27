/*
   author : harish vishwa
   Date   : 27 / 5 / 25
*/

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

class Solution {
public:
    vector<int> nextGreaterElementIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] >= arr[st.top()])
                st.pop();
            if (!st.empty()) nge[i] = st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> previousGreaterElementIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > arr[st.top()])
                st.pop();
            if (!st.empty()) pge[i] = st.top();
            st.push(i);
        }
        return pge;
    }
    vector<int> nextSmallerElementIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> previousSmallerElementIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()])
                st.pop();
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }

    ll sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = nextSmallerElementIndex(arr);
        vector<int> pse = previousSmallerElementIndex(arr);

        ll total = 0;
        for (int i = 0; i < n; i++) {
            ll left = i - pse[i];
            ll right = nse[i] - i;
            total += (ll)arr[i] * left * right;
        }
        return total;
    }

    ll sumSubarrayMaxi(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge = nextGreaterElementIndex(arr);
        vector<int> pge = previousGreaterElementIndex(arr);

        ll total = 0;
        for (int i = 0; i < n; i++) {
            ll left = i - pge[i];
            ll right = nge[i] - i;
            total += (ll)arr[i] * left * right;
        }
        return total;
    }

    ll subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxi(nums) - sumSubarrayMins(nums);
    }
};
