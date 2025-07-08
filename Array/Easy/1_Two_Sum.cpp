class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //BRUTE FORCE
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i]+nums[j] == target && i!=j){
                    return {i,j};
                }
            }
        }
        return{};   

        //OPTIMIZED 2SUM
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int c = target-nums[i];
            if(mp.find(c)!=mp.end()){
                return {i,mp[c]};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};