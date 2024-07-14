/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* data;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL || cloned==NULL){
            return NULL;
        }
        if(original->val==target->val && cloned->val==target->val){
            return data = cloned;
        }
        getTargetCopy(original->left,cloned->left,target);
        getTargetCopy(original->right,cloned->right,target);
        return data;
    }
};