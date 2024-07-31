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
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        if(ans==LONG_MAX) return -1;
        return ans;
    }
    int mn = INT_MAX;

    long long ans=LONG_MAX;
    void dfs(TreeNode* root){
        if(root==NULL) return;
        mn = min(mn,root->val);
        if(root->val<ans && root->val>mn) ans = root->val;
        
        dfs(root->left);
        dfs(root->right);
        
    }
};