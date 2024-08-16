class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0].front();
        int maxi = arrays[0].back();
        
        int res = 0;
        
        for(int i=1;i<arrays.size();i++){
            int currmin = arrays[i].front();
            int currmax = arrays[i].back();

            res = max({res,abs(currmax-mini),abs(maxi-currmin)});

            mini = min(mini,currmin);
            maxi = max(maxi,currmax);
        }
        return res;
    }
};