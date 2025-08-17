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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        while(curr!=NULL || !stack.empty()){
            while(curr!=NULL){
                stack.push(curr);
                curr = curr->left;    
            }
            curr = stack.top();
            stack.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};

//RECURSIVE
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
    void inorder(vector<int> &ans, TreeNode* root){
        if(root==NULL) return;
        inorder(ans,root->left);
        ans.push_back(root->val);
        inorder(ans,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(ans,root);
        return ans;
    }
};

//MORRIS TRAVERSAL
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev= prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};