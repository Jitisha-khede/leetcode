class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> output, int i){
        if(i>=nums.size()){
            ans.push_back(output);
            return;
        }

        //exclude
        solve(ans,nums,output,i+1);

        //include
        int elem = nums[i];
        output.push_back(elem);
        solve(ans,nums,output,i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(ans,nums,output,0);
        return ans;
    }
};