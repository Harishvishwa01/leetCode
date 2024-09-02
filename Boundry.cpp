#include <bits/stdc++.h>
using namespace std; 

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val) : val(val),left(nullptr),right(nullptr){}
};
class Solution{
   public:
     bool isLeaf(Node* root){
        return !root->left && !root->right;
     }
     void Left(Node* root,vector<int>& arr){
          Node* cur = root -> left;

          while(cur){
            if(!isLeaf(cur)){
                arr.push_back(cur->val);
            }
            if(cur -> left){
                cur = cur -> left;
            }
            else{
                cur = cur -> right;
            }
          }
     }
      void Right(Node* root,vector<int>& arr){
        vector<int> temp;
        Node* cur = root -> right;

        while(cur){
            if(!isLeaf(cur)){
                temp.push_back(cur -> val);
            }
            if(cur -> right){
                cur = cur ->right;

            }
            else{
                cur = cur -> left;
            }

        } 

       for(int i = temp.size() - 1; i >= 0; i--){
         arr.push_back(temp[i]);
     } 
      
      }
      void Leaf(Node* root,vector<int>& arr){
        if(isLeaf(root)){
            arr.push_back(root -> val);
            return;
        }

        if(root -> left){
             Leaf(root->left,arr);
        }
        if(root -> right){
            Leaf(root -> right,arr);
        }

     }
     vector<int> Boundary(Node* root){
        vector<int> ans;
        if(!root){
            return ans;
        }
        if(!isLeaf(root)){
            ans.push_back(root -> val);
        }
        Left(root,ans);
        Leaf(root,ans);
        Right(root,ans);
        return ans;
     }

};
void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
} 

int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the boundary traversal
    vector<int> result = solution.Boundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}