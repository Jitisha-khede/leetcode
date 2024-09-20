class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        unordered_map<string,int> st;
        if(s.size()<=10) return v;
        string temp = s.substr(0,10);
        st[temp]++;
        for(int i=10;i<s.size();i++){
            temp+=s[i];
            temp.erase(0,1);
            st[temp]++;          
        }
        for(auto it: st){
            if(it.second>=2){
                v.push_back(it.first);
            }
        }
        return v;
    }
};