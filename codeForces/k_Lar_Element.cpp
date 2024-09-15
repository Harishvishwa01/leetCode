#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       
        priority_queue<int> q;

        for (auto it : nums) {
            q.push(it);
        }
        long long num;
        for (int i = 0; i < k; i++) {
            num = q.top();
            q.pop();
        }

        return num;
    }
};

