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
    vector<int> vect;
    TreeNode* mover;
    TreeNode* increasingBST(TreeNode* root) {    
        TreeNode* dummy = new TreeNode(0);
        mover = dummy;
        dfs(root);
        return dummy->right;
    }
    void dfs(TreeNode* root){
        if(root==NULL){
            return;
        }
        dfs(root->left);
        mover->right = new TreeNode(root->val);
        mover = mover->right;
        dfs(root->right);
    }
};