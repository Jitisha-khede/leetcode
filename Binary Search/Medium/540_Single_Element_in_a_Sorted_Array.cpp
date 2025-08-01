//BRUTE FORCE: check linearly if adjacent elems are equal or not 
//BETTER
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int l =0, r= nums.size()-1;
        while(l<=r){
            if(nums[l]!=nums[l+1]) return nums[l];
            if(nums[r]!=nums[r-1]) return nums[r];
            l+=2;
            r-=2;
        }
        return -1;
    }
};
//OPTIMAL
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        int l = 1, r= nums.size()-2;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
            if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return -1;
    }
};