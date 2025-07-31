class Solution {
public:
    void generate(vector<int> &candidates,set<vector<int>> &ans, vector<int> temp, int i,int sum, int target){
        if(sum>=target || i>=candidates.size()){
            if(sum==target){
                ans.insert(temp);
            }
            return;
        }
        if(sum<=target){
            temp.push_back(candidates[i]);
            sum+=candidates[i];
            generate(candidates,ans,temp,i,sum,target);
        }
            sum-=candidates[i];
            temp.pop_back();
            generate(candidates,ans,temp,i+1,sum,target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> temp;
        int i=0;
        int sum =0;
        
        generate(candidates,ans,temp,i,sum,target);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};