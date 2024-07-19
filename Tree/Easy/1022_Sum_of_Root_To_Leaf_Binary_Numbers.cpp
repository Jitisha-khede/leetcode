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
    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        return sum;
    }
    string s;
    int sum=0;
    void dfs(TreeNode* root){
        if(root==NULL) return;
        s+=to_string(root->val);
        
        if(root->right==NULL && root->left==NULL){
            sum+=stoi(s,nullptr,2);
        }
        
        dfs(root->left);
        dfs(root->right);
        s.pop_back();
    }
};