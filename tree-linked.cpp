#include<bits/stdc++.h> 
 
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
    TreeNode* cur = NULL; // 0 6 5 
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root-> right);
        flatten(root -> left);
        root -> left = NULL;
        root -> right = cur;

        cur = root;
    }
};