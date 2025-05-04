#include <bits/stdc++.h>
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) return (1<<lh) - 1;

        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }

    int leftHeight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node -> left;
        }
        return height;
    }

    int rightHeight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node -> right;
        }
        return height;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

   cout<<sol.countNodes(root);
}