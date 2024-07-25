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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root != NULL) q.push(root);
        while(!q.empty()){
            int temp=INT_MIN;
            int qlen = q.size();
            for(int i=0;i<qlen;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node!=NULL){
                    temp = max(temp,node->val);
                    if(node->left!=NULL) q.push(node->left);
                    if(node->right!=NULL) q.push(node->right);
                }
            }
            ans.push_back(temp);
            
        }
        return ans;
    }
};