class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> a,b;
        vector<int> v;
        int k = p.size();
        for(int i=0;i<p.size();i++){
            b[p[i]]++;
        }

        for(int i=0;i<s.size();i++){
            a[s[i]]++;    
            if(i>=k){
                a[s[i-k]]--;
                if (a[s[i - k]] == 0) {
                    a.erase(s[i - k]);
                }
            }
            if(a==b) v.push_back(i-k+1);
        }
        return v;
    }
};