#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int x): val(x),right(nullptr),left(nullptr){}
};

class Solution{
  public :
  TreeNode* successor(TreeNode* root, TreeNode * p){
    TreeNode* success = NULL;

    while(root){
        if(p -> val > root -> val){
            root = root -> right;
        }
        else{
            success = root;
            root = root -> left;
        }
    }
    return success;
  }
};

int main(){
    
}