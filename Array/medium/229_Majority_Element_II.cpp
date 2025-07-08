class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int cnt1 = 0,cnt2=0,el1=0,el2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=el2){
                el1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=el1){
                el2=nums[i];
            }
            if(nums[i]==el1){
                cnt1++;
            }
            else if(nums[i]==el2){
                cnt2++;
            }
            else{
                cnt1--,cnt2--;
            }
        }

        cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
        }

        if(cnt1>n/3 && cnt2>n/3) return {el1,el2};
        else if(cnt1>n/3 && cnt2<=n/3) return {el1};
        else if(cnt1<=n/3 && cnt2>n/3)return {el2}; 
        return {};
    }
};