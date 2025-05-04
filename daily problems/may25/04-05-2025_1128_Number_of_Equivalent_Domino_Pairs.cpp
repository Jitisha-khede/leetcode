class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& d) {
            vector<int> v(100);
    
            for(auto it: d){
                int a = it[0],b=it[1];
                if(it[1]<it[0]){
                    a = it[1];
                    b = it[0];
                }
                int temp = a*10+b;
                v[temp]++;
            }
    
            int res=0;
            for(int i=0;i<v.size();i++){
                res+=v[i]*(v[i]-1)/2;
            }
            return res;
        }
    };