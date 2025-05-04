#include <bits/stdc++.h>
using namespace std;  
 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int maxSum(TreeNode* root,int& maxi){
        if(!root) return NULL;
        
        int leftt = max(0,maxSum(root->left,maxi));
        int rightt = max(0,maxSum(root -> right,maxi));
        maxi = max(maxi,leftt + rightt + root -> val);

        return max(leftt,rightt) + root -> val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxSum(root,maxi);
        return maxi;
    }
};