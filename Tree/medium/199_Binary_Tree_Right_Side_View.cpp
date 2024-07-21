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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vect;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int qlen = q.size();
            for(int i=0;i<qlen;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node!=NULL){
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(!level.empty()){
                vect.push_back(level[level.size()-1]);
            }
        }
        return vect;
    }
};