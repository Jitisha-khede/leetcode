class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<vector<int>,int> mp;
        set<int> st;
       int count=0;
        for(int i=0;i<pick.size();i++){
            mp[pick[i]]++;
        }

        for(auto& it : mp){
            cout<<it.first[0]<<" "<<it.first[1]<<" "<<it.second<<endl;
            if(it.first[0]+1<=it.second) st.insert(it.first[0]);
        }
        return st.size();
    }
};