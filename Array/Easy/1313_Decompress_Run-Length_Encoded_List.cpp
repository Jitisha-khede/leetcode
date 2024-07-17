class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> vect;
        int i=0;
        while(i<nums.size()-1){
            while(nums[i]--){
                vect.push_back(nums[i+1]);
            }
            i+=2;
        }
        return vect;
    }
};