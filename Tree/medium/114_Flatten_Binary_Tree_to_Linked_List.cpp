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
    void flatten(TreeNode* root) {
        queue<TreeNode*> q;
        dfs(root,q);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(q.empty() && node!=NULL) node->right==NULL;
            else{
                node->right = q.front();
                node->left = NULL;
            }
        }
    }

    void dfs(TreeNode* root,queue<TreeNode*> &q){
        if(root==NULL) return;
        q.push(root);
        dfs(root->left,q);    
        dfs(root->right,q);
    }
};