class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return nums.size();
        sort(nums.begin(),nums.end());
        int maxi=0,count=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) continue;
            if(nums[i]+1==nums[i+1]){
                count++;
            }
            maxi = max(maxi,count);
            if(nums[i]+1!=nums[i+1]){    
                count=0;
            }
        }
        return maxi+1;
    }
};