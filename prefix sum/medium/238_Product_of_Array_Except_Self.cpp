class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int num1=1;
        int c = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) num1*=nums[i];
            if(nums[i]==0) c++;
        }
        for(int i=0;i<nums.size();i++){
            if(c==1){
                if(nums[i]==0) nums[i]=num1;
                else nums[i] = 0;
            }
            else if(c>1){
                nums[i]=0;
            }
            else{
                nums[i] = num1/nums[i];
            }
        }
        return nums;
    }
};