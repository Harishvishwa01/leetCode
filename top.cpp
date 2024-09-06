#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
   
    vector<int> topView(Node* root){
      vector<int> ans;
      if(root == NULL) return  ans;
      map<int,int> mpp;
      queue<pair<Node*,int>> q;
      q.push({root,0});

      while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* tree = it.first;
        int line = it.second;
       
            mpp[line] = tree->data;
        
        if(tree->left != NULL) q.push({tree->left,line - 1});
        if(tree -> right != NULL) q.push({tree->right,line + 1});
      }
      for(auto it : mpp){
        ans.push_back(it.second);
      }
    }
};

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    // Get the top view traversal
    vector<int> topView =
                    solution.topView(root);

    // Print the result
    cout << "Top View Traversal: "<< endl;
    for(auto node: topView){
        cout << node << " ";
    }

    return 0;
}                   
         