class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int c = 0;
        string s = to_string(num);
        string temp;
        for(int i=0;i<k;i++){
            temp+=s[i];
        }
        if(stoi(temp)!=0 && num%stoi(temp)==0) c++;
        temp.clear();
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            if(i>=k){
                temp.erase(temp.begin());
                if(stoi(temp)!=0 && num%stoi(temp)==0) c++;
            }
        }
        return c;
    }
};