class Solution {
    public:
        int minDominoRotations(vector<int>& t, vector<int>& b) {
            unordered_map<int,int> mp;
            int n = t.size();
            for(int i=0;i<n;i++){
                if(t[i]!=b[i]){
                    mp[t[i]]++;
                    mp[b[i]]++;
                }
                else if(t[i]==b[i]) mp[t[i]]++;
            }
           
            vector<int> v;
    
            for(auto it: mp){
                if(it.second>=n){
                    v.push_back(it.first);
                }
            }
            if(v.size()==0) return -1;
            int mini = INT_MAX,res=INT_MAX;
    
            for(int i=0;i<v.size();i++){
                int c=0;
                for(int j=0;j<n;j++){
                    if(t[j]!=v[i] && b[j]==v[i]) c++;
                }
                mini = min(mini,c); 
            }
    
            for(int i=0;i<v.size();i++){
                int c=0;
                for(int j=0;j<n;j++){
                    if(t[j]==v[i] && b[j]!=v[i]) c++;
                }
                res = min(res,c); 
            }
            return min(mini,res);
        }
    };