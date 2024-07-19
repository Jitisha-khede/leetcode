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
    
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        vector<int> vect;
        dfs(root,mp);
        int max_count=0;
        for (auto i : mp) { 
            if (max_count < i.second) {
                vect.clear();
                vect.push_back(i.first);
                max_count = i.second; 
            } 
            else if(max_count==i.second){
                vect.push_back(i.first);
            }
        } 
        return vect;
    }

    void dfs(TreeNode* root,unordered_map<int,int>& mp){
        if(root==NULL) return;
        mp[root->val]++;
        dfs(root->left,mp);
        dfs(root->right,mp);
    }
};