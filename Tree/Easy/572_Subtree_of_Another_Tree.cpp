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
    bool result;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL){
            return true;
        }
        if(root==NULL){
            return false;
        }
        if(check(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }

    bool check(TreeNode* root, TreeNode* subRoot){
        if((root==NULL && subRoot!=NULL) || (root!=NULL && subRoot==NULL)){
            return false;
        }
        if(root==NULL && subRoot==NULL){
            return true;
        }
        if(root->val!=subRoot->val){
            return false;
        }

       bool l = check(root->left,subRoot->left);
       bool r =  check(root->right,subRoot->right);

       return l && r;
    }
};