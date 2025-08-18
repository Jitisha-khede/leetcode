//RECURSIVE
class Solution {
public:
    void rle(int n,string &s,int c){
        if(c==n-1) return;
        int sSize = s.size();
        string temp;
        int count = 1;
        for(int i=0;i<sSize;i++){
            if(i+1<sSize && s[i]==s[i+1]){
                count++;
            }
            else{
                temp+=to_string(count);
                temp+=s[i];
                count=1;
            }
        }
        s=temp;
        rle(n,s,c+1);
    }
    string countAndSay(int n) {
        string s = "1";
        rle(n,s,0);
        return s;
    }
};

//ITERATIVE
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i=1;i<n;i++){
            int sSize = s.size();
            int count = 1;
            string temp;
            
            for(int i=0;i<sSize;i++){
                if(s[i]==s[i+1]){
                    count++;
                }
                else{
                    temp+=to_string(count);
                    temp+=s[i];
                    count = 1;
                }
            }
            s = temp;
        }
        return s;
    }
};