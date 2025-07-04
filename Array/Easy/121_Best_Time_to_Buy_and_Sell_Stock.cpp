class Solution {
public:
    int maxProfit(vector<int>& p) {

        //BRUTE FORCE
        // int ans = 0;
        // for(int i=0;i<p.size();i++){
        //     for(int j=i+1;j<p.size();j++){
        //         if(p[i]<p[j]){
        //             ans = max(ans,p[j]-p[i]);
        //         }
        //     }
        // }
        // return ans;

        //OPTIMAL
        int mini = INT_MAX,ans=0;
        for(int i=0;i<p.size();i++){
            mini = min(p[i],mini);
            ans = max(ans,p[i]-mini);
        }
        return ans;
    }
};