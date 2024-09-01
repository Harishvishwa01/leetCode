#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;

    Node(int x): val(x),right(nullptr),left(nullptr){}
};

class Solution{
     public:
           void rig(Node* root,int height,vector<int>& arr){
                     if(root == NULL) return;

                     if(arr.size() == height){
                        arr.push_back(root->val);
                     }
                     rig(root->right,height+ 1,arr);
                     rig(root->left,height + 1,arr);
           }
           vector<int> right(Node* root){
               vector<int> ans;
               
               rig(root,0,ans);
               return ans;
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

        
    vector<int> rightView = solution.right(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for(auto node: rightView){
        cout << node << " ";
    }
    cout << endl;

  

    return 0;
}