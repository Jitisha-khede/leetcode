class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //BETTER
        // int c = 0,ans=0;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1]) continue;
        //     else if(nums[i]+1==nums[i+1]){
        //         c++;
        //         ans = max(c,ans);
        //     }
        //     else{
        //         c=0;
        //     }
        // }
        // return ans+1;

        //OPTIMAL
        if(nums.size()==0)return 0;
        int ans = 0;
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int c=0;
                int x = it;
                while(st.find(x+1)!=st.end()){
                    c++;
                    x++;
                }
                ans = max(ans,c);
            }
        }
        return ans+1;
    }
};