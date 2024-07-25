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
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }

    int temp = 0;
    void dfs(TreeNode* &root){
        if(root==NULL) return;

        dfs(root->right);
        cout<<root->val<<" ";
        if(temp==0) temp+=root->val;
        else{
            root->val += temp; 
            temp = root->val;
        }
        dfs(root->left); 

    }
};