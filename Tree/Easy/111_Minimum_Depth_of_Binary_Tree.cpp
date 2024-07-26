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
 #include <algorithm>
class Solution {
public:
    int ans = INT_MAX,count =0;
    int minDepth(TreeNode* root) {
        if(root==NULL) return NULL;
       dfs(root);
       return ans+1;    
    }
    void dfs(TreeNode* root){
        if(root==NULL) return;

        if(root->left==NULL && root->right==NULL) ans = min(ans,count);
        count++;

        dfs(root->left);
        dfs(root->right);
        count--;
    }
};