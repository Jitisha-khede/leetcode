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
    vector<int> vect;
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return vect;
    }
    void preOrder(TreeNode* root){
        if(root==NULL){
            return;
        }
        vect.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
};

//MORRIS TRAVERSAL
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;
        TreeNode* curr = root;

        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev =curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};