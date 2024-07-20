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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> db;
        queue<TreeNode*> q;
        q.push(root);
        int qlen;
        double sum;
        while(!q.empty()){
            vector<int> level;
            qlen=q.size();
            sum=0;
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
                for(int i=0;i<level.size();i++){
                    sum+=level[i];
                }
                sum/=level.size();
                db.push_back(sum);
            }    
        }
        return db;
    }
};