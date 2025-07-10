class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_set<char> st;
        int sum=INT_MIN;
        int l=0;
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])!=st.end()){
                while(l<i && st.find(s[i])!=st.end()){
                    st.erase(s[l]);
                    l++;
                }
            }
            st.insert(s[i]);
            sum = max(sum,i-l+1);
        }
        return sum;
    }
};
