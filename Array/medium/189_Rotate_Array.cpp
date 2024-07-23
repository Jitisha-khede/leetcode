class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        vector<int> vect;
        for(int i=nums.size()-k;i<nums.size();i++){
            vect.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()-k;i++){
            vect.push_back(nums[i]);
        }
        nums.clear();
        nums = vect;
    }
};