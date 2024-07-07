class Solution {
public:
    vector<string> validStrings(int n) {
        string s = "";
        vector<string> temp;
        
        if(n==1){
            s = to_string(0);
            temp.push_back(s);
            s = to_string(1);
            temp.push_back(s);
            return temp;
        }
        for(int i=1;i<pow(2,n);i++){
            int flag = 0;
            bitset<32> binary(i);
            s = binary.to_string().substr(32-n);
            for(int j=0;j<n-1;j++){
                if(s[j]!='1' && s[j+1]!='1'){
                    flag = 1;
                    break;
                }
            }
            if(flag==0){
                temp.push_back(s);
            }    
        }
        return temp;
    }
};