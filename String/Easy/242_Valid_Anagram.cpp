//APPROACH-1
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s!=t) return false;
        else return true;
    }
};
//APPROACH-2

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it: mp){
            if(it.second!=0) return false;
        }
        return true;
    }
};