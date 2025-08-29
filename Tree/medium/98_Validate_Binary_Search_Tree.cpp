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
    bool isValidBST(TreeNode* root) {
        checkBST(root);
        for(int i=0;i<vect.size()-1;i++){
            if(vect[i]>=vect[i+1]){
                return false;
            }
        }
        return true;
    }

    void checkBST(TreeNode* root){
        if(root==NULL){
            return;
        }
        checkBST(root->left);
        vect.push_back(root->val);
        checkBST(root->right);
    }
};

//OPTIMAL : CONSTANT SPACE
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL; 
        return checkBST(root,prev);
    }

    bool checkBST(TreeNode* root, TreeNode* &prev){
        if(root==NULL) return true;
        if(!checkBST(root->left,prev)) return false;
        if(prev!=NULL && prev->val >= root->val) return false;
        prev = root;
        return checkBST(root->right,prev);
    }
};