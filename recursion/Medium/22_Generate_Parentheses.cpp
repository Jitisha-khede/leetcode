class Solution {
public:
    void generate (int open,int close,int n, vector<string> &ans, string &temp){
        if(open==n && close==n){
            ans.push_back(temp);
            return;
        }

        else if(open<n){
            temp+='(';
            generate(open+1,close,n,ans,temp);
            temp.pop_back();
        }

        if(close<open){
            temp+=')';
            generate(open,close+1,n,ans,temp);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        generate(0,0,n,ans,temp);
        return ans;
    }
};