class Solution {
public:
    string getEncryptedString(string s, int k) {
        string s1,s2;
        k=k%s.size();
        s1 = s.substr(0,k);
        s2 = s.substr(k,s.size()-k);
        s = s2+s1;
        return s;
    }
};