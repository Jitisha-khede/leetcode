/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        inorder(root);
        return sum;
    }
    int sum=0;
    string s;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        s+=to_string(root->val);
        if(root->right==NULL && root->left==NULL){
            sum+=stoi(s);
        }
        inorder(root->left);
        inorder(root->right);
        s.pop_back();
    }
};