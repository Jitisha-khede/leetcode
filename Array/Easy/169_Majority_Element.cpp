class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int,int> mp;
        // int ans = 0;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it: mp){
        //     if(it.second>nums.size()/2){
        //         ans = it.first;
        //         break;
        //     }
        // }
        // return ans;

        //OPTIMAL
        int el=nums[0],cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt == 0) el = nums[i];
            if(nums[i]==el) cnt++;
            else{
                cnt--;
            }
        }
        return el;
    }
};