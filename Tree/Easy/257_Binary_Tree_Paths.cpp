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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string s;
        dfs(v,s,root);
        return v;
    }
    
    void dfs(vector<string> &v,string s,TreeNode* root){
        if(root->right==NULL && root->left==NULL){
            s+=to_string(root->val);
            v.push_back(s);
            s="";
            return;
        }
        s+=to_string(root->val);
        s+="->";
        if(root->left)dfs(v,s,root->left);
        if(root->right)dfs(v,s,root->right);
    }
};