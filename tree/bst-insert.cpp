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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        TreeNode* temp = root;
        TreeNode* parent = nullptr;
        while(temp){
            parent = temp;
            if(temp -> val < val){
                temp = temp -> right;
            }
            else {
                temp = temp -> left;
            }
        }
        TreeNode* node = new TreeNode(val);
        if(parent -> val > val){
            parent -> left = node;
        }
        else{
            parent -> right = node;
        }

        return root;
    }
};

int main(){
    
}