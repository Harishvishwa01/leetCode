#include <bits/stdc++.h>
using namespace std;  

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string  s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            if(cur == NULL) s.append("#,");
            else{
                s += to_string(cur -> val) + ",";
                q.push(cur -> left);
                q.push(cur -> right);
            } 
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;

        getline(s,str,',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();
             getline(s, str, ',');
            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(s, str, ',');

            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};