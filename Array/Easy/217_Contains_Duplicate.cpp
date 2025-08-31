class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //BRUTE FORCE
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]) return true;
            }
        }
        return false;

        //BETTER

        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) return true;
        }
        return false;

        //OPTIMAL
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            if(it.second>1) return true;
        }
        return false;
    }
};