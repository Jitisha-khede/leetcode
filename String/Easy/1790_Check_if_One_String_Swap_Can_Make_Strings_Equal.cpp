class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        map<char,int> mp1,mp2;
        int c=0;
        for(int i=0;i<s1.size();i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        if(mp1!=mp2) return false;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                c++;
                if(c>2) return false;
            }
        }
        if(c==2 || c==0) return true;
        return false;
    }
};