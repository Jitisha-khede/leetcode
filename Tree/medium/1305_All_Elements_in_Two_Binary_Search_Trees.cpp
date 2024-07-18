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
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vect,vect1,vect2; 
        inorder(root1,vect1);
        inorder(root2,vect2);
        vect.insert(vect.end(), vect1.begin(), vect1.end());
        vect.insert(vect.end(), vect2.begin(), vect2.end());
        sort(vect.begin(),vect.end());
        return vect;
    }

    void inorder(TreeNode* root,vector<int>& vect){
        if(root==NULL) return; 
        inorder(root->left,vect);
        vect.push_back(root->val);
        inorder(root->right,vect);
    }
};