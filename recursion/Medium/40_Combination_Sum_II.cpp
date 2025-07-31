class Solution {
public:
    void generate(vector<int> &candidates,set<vector<int>> &ans, vector<int> temp, int i,int sum, int target){
        if(sum>=target || i>=candidates.size()){
            if(sum==target){
                ans.insert(temp);
            }
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1])continue;
            if(candidates[j]>target) break;
            temp.push_back(candidates[j]);
            generate(candidates,ans,temp,j+1,sum+candidates[j],target);
            // temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> temp;
        int i=0;
        int sum =0;
        sort(candidates.begin(),candidates.end());
        generate(candidates,ans,temp,i,sum,target);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};