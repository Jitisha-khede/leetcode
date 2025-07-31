class Solution {
public:
    bool isPalindrome(string s,int l, int r){
        if(s.size()==1) return true;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void generate(string s, vector<string> &mid, vector<vector<string>> &ans, int ind){
        if(ind>=s.size()){
            ans.push_back(mid);
            return;
        }

        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                mid.push_back(s.substr(ind,i-ind+1));
                generate(s,mid,ans,i+1);
                mid.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        generate(s,temp,ans,0);
        return ans;
    }
};