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
    int sum = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        inorder(root,targetSum);
        if(flag==0) return false;
        return true;
    }
    int flag=0;
    void inorder(TreeNode* root,int targetSum){
        if(root==NULL) return;
        sum+=root->val;
        if(sum==targetSum && root->right==NULL && root->left==NULL){
            flag=1;
            return;
        }
        inorder(root->left,targetSum);
        inorder(root->right,targetSum);
        sum-=root->val;
    }
};