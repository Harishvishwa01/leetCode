/*
   author : harish vishwa
   Date   : 27 / 5 / 25
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElementIndex(vector<int> arr){
        int n = arr.size();
        vector<int> nse(n,-1);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() and arr[i] <= arr[st.top()]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> previousSmallerElementIndex(vector<int> arr){
         int n = arr.size();
         stack<int> st;
         vector<int> pse(n,-1);
         for(int i = 0; i < n; i++){
            while(!st.empty() and arr[i] < arr[st.top()]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
         }
         return pse;
    }
   int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxi = 0;
    vector<int> nse = nextSmallerElementIndex(heights);
    vector<int> pse = previousSmallerElementIndex(heights);
    
    for(int i = 0; i < n; i++){
        int right = (nse[i] == -1 ? n : nse[i]);
        int width = right - pse[i] - 1;
        maxi = max(maxi, width * heights[i]);
    }
    return maxi;
}
};
