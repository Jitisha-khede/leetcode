/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
    void preorder(Node *node,int level, vector<int> &ans){
        if(node==NULL) return;
        
        if(level==ans.size()) ans.push_back(node->data);
        preorder(node->left,level+1,ans);
        preorder(node->right,level+1,ans);
    }
    vector<int> leftView(Node *root) {
        vector<int> ans;
        preorder(root,0,ans);
        return ans;
    }
    
};