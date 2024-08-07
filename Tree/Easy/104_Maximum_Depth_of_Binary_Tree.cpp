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

//using bfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int count=0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode* curr;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            //checking new level
            if(curr==NULL){
                count++;
                //inserting NULL for next level identification
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if(curr->left!=NULL){
                q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
        }
        return count;
    }
};

//using recursion

