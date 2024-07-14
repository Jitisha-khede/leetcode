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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
       vector<int> vect1;
       vector<int> vect2;

       leaf(root1,vect1);
       leaf(root2,vect2);

        if(vect1.size()!=vect2.size()){
            return false;
        }
        for(int i=0;i<vect1.size();i++){
            if(vect1[i]!=vect2[i]){
                    return false;
            }
       }
       return true;   
    };

    void leaf(TreeNode*root, vector<int>& vect){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            vect.push_back(root->val);
        }
        leaf(root->left,vect);
        leaf(root->right,vect);
    }
};
