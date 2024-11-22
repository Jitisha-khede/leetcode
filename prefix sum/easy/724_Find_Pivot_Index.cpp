class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sl=0, sr=0;
        for(int i=0;i<nums.size();i++){
            sr+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(sl==sr-(nums[i]+sl)) return i;
            sl+=nums[i];
        }
        return -1;
    }
};