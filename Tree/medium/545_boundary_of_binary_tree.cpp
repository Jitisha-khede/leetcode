/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    void leftSide(Node* root, vector<int> &res){
        root = root->left;
        while(root){
            if(root->right!=NULL || root->left!=NULL) res.push_back(root->data);
            if(root->left) root = root->left;
            else root = root->right;
        }
    }
    void leafNodes(Node* root, vector<int> &res){
        if(root==NULL) return;
        if(root->right==NULL && root->left==NULL){
            res.push_back(root->data);
        }
        leafNodes(root->left,res);
        leafNodes(root->right,res);
    }
    
    void rightSide(Node* root, vector<int> &res){
        vector<int> temp;
        root = root->right;
        while(root){
            if(root->right!=NULL || root->left!=NULL)temp.push_back(root->data);
            if(root->right) root = root->right;
            else root = root->left;
        }
        for(int i=temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        res.push_back(root->data);
        leftSide(root,res);
        if(root->left || root->right)  leafNodes(root,res);
        rightSide(root,res);
        return res;
    }
};