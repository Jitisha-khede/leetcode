class Solution {
public:
    void generate(string &ans,string s, string &temp, int &c, int k){
                
        if(c==k){
            return;
        }

        if(s.size()==temp.size()){
            ans = temp;
            c++;
        }
        
        for(int i=0;i<s.size();i++){
            if(temp.find(s[i])==string::npos){
                temp+=s[i];
                generate(ans,s,temp,c,k);
                temp.pop_back();
            }
        }
    }
    string getPermutation(int n, int k) {
        string s;
        for(int i=1;i<=n;i++){
            s+=to_string(i);
        }
        int c=0;
        string temp;
        string ans;
        generate(ans,s,temp,c,k);
        return ans;
    }
};