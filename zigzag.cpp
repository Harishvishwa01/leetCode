#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class solution{
vector<vector<int>> ZigZag(Node* root){
      vector<vector<int>> arr;
      if(!root) return arr;
      
      queue<Node*> q;
      q.push(root);
      bool ltr = true;
      while(!q.empty()){
        int size = q.size();

        vector<int> col;
        for(int i = 0; i<  size; i++){
            Node* node = q.front();
            q.pop();
           int index = ltr ?i : (size - 1 - i);
           col[index] = node -> data;
           if(node->left ) q.push(node->left);
           if(node->right) q.push(node->right);
        }
        arr.push_back(col);
        ltr = !ltr;
      }
     return arr;
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

    solution solution;

        
    vector<vector<int>> rightView = solution.ZigZag(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for(auto node: rightView){
        cout << node << " ";
    }
    cout << endl;

  

    return 0;
}