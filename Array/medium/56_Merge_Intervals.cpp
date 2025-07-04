class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>> ans;
        int start =0,end=0;
        sort(in.begin(),in.end(),[](const vector<int> &a,const vector<int> &b){
            return a[0]<b[0];
        });
        for(int i=0;i<in.size();i++){
           if(ans.empty() || in[i][0]>ans.back()[1]){
            ans.push_back(in[i]);
           }
           else{
            ans.back()[1] = max(ans.back()[1],in[i][1]);
           }
        }
        return ans;
    }
};