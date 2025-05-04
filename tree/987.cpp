#include <bits/stdc++.h>
using namespace std;  
#define ll long long 


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
   

};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
             vector<vector<int>> ans;
             if(root == NULL) return ans;

        map<int, map<int, multiset<int>>> nodes;
     
        queue<pair<TreeNode*, pair<int, int>>> todo;
        
     
        todo.push({root, {0, 0}});
        
        // BFS traversal
        while(!todo.empty()){
           auto p = todo.front();
            todo.pop();
            TreeNode* temp = p.first;
        
            int x = p.second.first;  
            // y -> level
            int y = p.second.second; 
            nodes[x][y].insert(temp->val);
            
            if (temp->left != NULL)
                todo.push({temp->left, {x - 1, y + 1}});
            if (temp->right != NULL)
                todo.push({temp->right, {x + 1, y + 1}});
        }
      
           for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
   }
};