class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int sr=0,sl=0,c=0;
        for(int i=0;i<nums.size();i++){
            sr+=nums[i];
        }
        for(int i=0;i<nums.size()-1;i++){
            sl+=nums[i];
            if(sl>=sr-sl) c++;   
        }
        return c;
    }
};