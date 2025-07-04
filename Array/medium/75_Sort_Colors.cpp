class Solution {
public:
    void sortColors(vector<int>& nums) {
        //BRUTE FORCE

        // for(int i=0;i<nums.size();i++){
        //     bool flag = 0;
        //     for(int j=0;j<nums.size()-1;j++){
        //         if(nums[j]>nums[j+1]){
        //             swap(nums[j],nums[j+1]);
        //             flag = 1;
        //         }
        //     }
        //     if(flag == 0) break;
        // }

        //OPTIMAL
        int n = nums.size();
        int mid = 0,low=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};