//BRUTE FORCE
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        bool flag = 0;
        for(int i=0;i<strs[0].size();i++){
            for(int j=0;j<strs.size()-1;j++){
                if(strs[j][i]!=strs[j+1][i]){
                    flag = 1;
                }
            }
            if(flag == 1) return s;
            s+=strs[0][i];
        }
        return s;
    }
};

//OPTIMAL
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        sort(strs.begin(),strs.end());
        for(int i=0;i<strs[0].size();i++){
            if(strs[0][i]==strs[strs.size()-1][i]) s+=strs[0][i];
            else return s;
        }
        return s;
    }
};