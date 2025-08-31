class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //BRUTE FORCE
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j] && abs(j-i)<=k) return true;
            }
        }
        return false;

        //OPTIMAL
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            if(i>k){
                mp[nums[i-k-1]]--;
            }
            if(mp.find(nums[i])!=mp.end() && mp[nums[i]]>0) return true;
            mp[nums[i]]++;
        }        
        return false;
    }
};