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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr=root;
        int flag=0;
        if(root==NULL){
            TreeNode* dummy = new TreeNode(val);
            return dummy;
        }
        while(curr!=NULL){
            if(val>curr->val){
                if(curr->right==NULL){
                    flag=0;
                    break;
                }
                curr=curr->right;
            }
            else{
                if(curr->left==NULL){
                    flag=1;
                    break;
                }
                curr=curr->left;
            }
        }
        if(flag==0){
            TreeNode* dummy = new TreeNode(val);
            curr->right = dummy;
        }
        if(flag==1){
            TreeNode* dummy = new TreeNode(val);
            curr->left = dummy;
        }
        return root;
    }
};