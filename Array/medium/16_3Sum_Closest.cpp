class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        int res = 0;

        for(int i=0;i<nums.size();i++){
            int j=i+1, k=nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(target-sum)<ans){
                    res = sum;
                    ans = abs(target-sum);
                }
                if(sum>target) k--;
                else j++;
            } 
        }
        return res;
    }
};