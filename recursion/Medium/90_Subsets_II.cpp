class Solution {
public:
    void generate(set<vector<int>> &ans,vector<int> &nums, vector<int> temp, int i){
        if(i==nums.size()){
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        generate(ans,nums,temp,i+1);
        temp.pop_back();
        generate(ans,nums,temp,i+1);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        int i=0;
        generate(ans,nums,temp,i);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};