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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return bulid(preorder,i,LONG_MAX);
    }
    TreeNode* bulid(vector<int> & arr,int& i,long long bound){
        if(i == arr.size() || arr[i] > bound) return NULL;
        TreeNode* root = new TreeNode(arr[i++]);
        root -> left = bulid(arr,i, root -> val);
        root -> right = bulid(arr,i,bound);
        return root;
    }
};

int main(){
    
}