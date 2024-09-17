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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = bulid(inorder,0,inorder.size() - 1, postorder,0,postorder.size() -1,mpp);

        return root;
    }

    TreeNode* bulid(vector<int>& inorder,int is,int ie, vector<int>& postorder,int ps,int pe,map<int,int>& mpp){
        if(is > ie || ps > pe) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int index = mpp[root -> val];
         int leftside = index - is;
        root -> left = bulid(inorder,is,index - 1,postorder,ps,ps+leftside - 1 ,mpp);
        root -> right =bulid(inorder,index + 1,ie,postorder,ps + leftside,pe - 1,mpp);
        return root;
    }
};