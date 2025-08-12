class Solution {
public:
    //BRUTE FORCE
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int c=0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            bool flag = 0;
            for(int j=1;j<nums.size();j++){
                if(nums[(j+i)%n]>nums[i]){
                    ans.push_back(nums[(j+i)%n]);
                    flag = 1;
                    break;
                }
            }
            if(flag==0) ans.push_back(-1);
        }
        return ans;
    }

    //OPTIMAL
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        stack<int> st;

        for(int i=n*2-1;i>=0;i--){
            while(!st.empty() && nums[i%n]>=st.top()) st.pop();
            if(i<n){
                if(st.empty()){
                    ans[i] = -1;
                }
                else{
                    ans[i] = st.top();
                }
            }
            st.push(nums[i%n]);
        } 
        return ans;   
    }
};