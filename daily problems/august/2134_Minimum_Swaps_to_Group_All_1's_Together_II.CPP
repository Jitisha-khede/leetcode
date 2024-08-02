class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size(),k=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) k++;
        }
        nums.insert(nums.end(),nums.begin(),nums.end());

        int count=0;
        int ans = k;
        for(int i=0;i<2*n;i++){
            if(nums[i]==1) count++;

            if(i>=k){
                if(nums[i-k]==1) count--;
                ans = min(ans,k-count);
            }
        }
        return ans;
    }
};