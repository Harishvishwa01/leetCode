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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = bulid(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);

        return root;
    }
    TreeNode* bulid(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie,map<int,int>& mpp){
        if(is > ie || ps > pe) return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);

        int index = mpp[root -> val];

        int leftside = index - is;

        root -> left = bulid(preorder,ps + 1,ps + leftside,inorder,is,index - 1,mpp);
        root -> right = bulid(preorder,ps + leftside + 1,pe, inorder,index + 1,ie,mpp);

        return root;
    }
};