class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // set<vector<int>> st;
        // for(int i=0;i<nums.size();i++){
        //     set<int>hashSet;
        //     for(int j=i+1;j<nums.size();j++){
        //         int third = -(nums[i]+nums[j]);
        //         if(hashSet.find(third)!=hashSet.end()){
        //             vector<int> temp = {nums[i],nums[j],third};
        //             sort(temp.begin(),temp.end());
        //             st.insert(temp);
        //         }
        //         hashSet.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>> ans(st.begin(),st.end());
        // return ans; 

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int i=0;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }  
        }
        return ans;
    }
};