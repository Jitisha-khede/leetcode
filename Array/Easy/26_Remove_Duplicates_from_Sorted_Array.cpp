//BRUTE FORCE
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        int i=0;
        for(auto& it : st){
            nums[i] = it;
            i++;
        }
        return i;
    }
};

//OPTIMAL
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int r = 1;
        int l = 0;
        int k = 1;
        while(r<nums.size()){
            if(nums[l]==nums[r]) r++;
            else{
                nums[l+1] = nums[r];
                l++;
                k++;
            }
        }
        return k;
    }
};