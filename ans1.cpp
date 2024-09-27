#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mpp;
        for(auto it : nums){
            mpp[nums[it]]++;
        }
        for(auto it : mpp){
            if(it.first >= 2){
                ans.push_back(it.second);
            }
        }

        return ans;
    }
};

int main(){
    Solution a;
    vector<int> arr = {0,3,2,1,3,2};
    vector<int> newar;
    newar= a.getSneakyNumbers(arr);
    for(auto it : newar){
        cout<<it<<" ";
    }
}