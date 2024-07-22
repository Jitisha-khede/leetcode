class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi=-10000;
        double count=0;
        for(int i=0;i<k;i++){
            count+=nums[i];
        }
        maxi=max(maxi,count/k);
        for(int i=k;i<nums.size();i++){
            count+=nums[i];
            if(i>=k){
                count-=nums[i-k];
            }
            maxi=max(maxi,count/k);
        }
        return maxi;
    }
};