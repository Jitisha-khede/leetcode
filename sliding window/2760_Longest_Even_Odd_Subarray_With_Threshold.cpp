class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int count=0;
        int i=0;
        int maxi=0;
        bool flag = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0 && nums[i]<=threshold && flag==0){
                count=1;
                flag = 1;
            }
           
            else if (flag==1){
                if(nums[i-1]<=threshold && nums[i]%2!=nums[i-1]%2 && nums[i]<=threshold) count++; 
                else flag=0,i--;
            } 
            
            maxi = max(count,maxi); 
        }
        
        return maxi;
    }
};