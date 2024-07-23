class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        set<char> st1;
        set<char> st2;

        multiset<int>  ms1;
        multiset<int> ms2;

        for(int i=0;i<word1.size();i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }

        for(auto it=mp1.begin();it!=mp1.end();it++){
            st1.insert(it->first);
            ms1.insert(it->second);
        }

        for(auto it=mp2.begin();it!=mp2.end();it++){
            st2.insert(it->first);
            ms2.insert(it->second);
        }

        return ms1==ms2 && st1==st2;
 
    }
};