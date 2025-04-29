class Solution {
    public:
        bool isPalindrome(string s) {
            string st;
            transform(s.begin(),s.end(),s.begin(),[](unsigned char c){ return std::tolower(c); });
            for(int i=0;i<s.size();i++){
                if(isalnum(s[i])) st+=s[i];
            }
            for(int i=0;i<st.size();i++){
                if(st[i]!=st[st.size()-1-i]) return false;
            }
            return true;
        }
    };