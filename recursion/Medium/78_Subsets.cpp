class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, int i){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(ans,nums,temp,i+1);
        temp.pop_back();
        solve(ans,nums,temp,i+1);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(ans,nums,output,0);
        return ans;
    }
};