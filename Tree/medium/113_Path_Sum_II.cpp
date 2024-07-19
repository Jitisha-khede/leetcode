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
    vector<vector<int>> vect;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        inorder(root,targetSum);
        return vect;
    }

    vector<int>temp;
    int sum=0;
    void inorder(TreeNode* root,int targetSum){
        if(root==NULL) return;
        temp.push_back(root->val);
        sum+=root->val;
        
        if(sum==targetSum && root->right==NULL && root->left==NULL){
            vect.push_back(temp);
        }
        inorder(root->left,targetSum);
        inorder(root->right,targetSum);
        sum-=root->val;
        temp.pop_back();
    }
};