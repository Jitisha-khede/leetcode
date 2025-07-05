class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=nums[0];
        int slow=nums[0];
        do{
            slow = nums[slow];//move by 1
            fast = nums[nums[fast]];//move by 2 
        }while(slow!=fast);

        slow = nums[0];//find entrance of cycle
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};