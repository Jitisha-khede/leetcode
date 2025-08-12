class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string temp,ans;

        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else if(!temp.empty() && s[i]==' '){
                v.push_back(temp);
                temp.clear();
            }
        }
        if(!temp.empty()) v.push_back(temp);

        for(int i=v.size()-1;i>=0;i--){
            ans+=v[i];
            ans+=' ';
        }

        ans.pop_back();

        return ans;
    }
};