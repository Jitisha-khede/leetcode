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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vect;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 0;

        while(!q.empty()){
            int qlen=q.size();
            vector<int> level;
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
                if(flag==0){
                    vect.push_back(level);
                    flag=1;
                }
                else if(flag==1){
                    reverse(level.begin(),level.end());
                    vect.push_back(level);
                    flag=0;
                }
            }
        }
        return vect;
    }
};