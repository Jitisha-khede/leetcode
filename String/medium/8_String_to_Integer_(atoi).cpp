class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        long long res=0;
        int i=0;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='-') {
            sign = -1;
            i++;
        }
        else if(s[i]=='+'){
            sign = 1;
            i++;
        }
        while(s[i]){
            if(res*sign>pow(2,31)-1) return pow(2,31)-1;
            else if(res*sign<pow(-2,31)) return pow(-2,31);
            else if(s[i]-'0'<0 || s[i]-'0'>9){
                break;
            } 
            else{
                res=res*10+(s[i]-'0');
            }
            i++;
        }
        if(res*sign>pow(2,31)-1) return pow(2,31)-1;
        else if(res*sign<pow(-2,31)) return pow(-2,31);
        return res*sign;
    }
};