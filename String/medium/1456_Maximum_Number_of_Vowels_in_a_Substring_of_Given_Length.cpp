class Solution {
public:
    int maxVowels(string s, int k) {
        int maxi=0;
        for(int i=0;i<=s.size()-k;i++){
            int count = 0;
            
            for(int j=i;j<k+i;j++){
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                    count++;
                }
            }
            maxi=max(count,maxi);
        }
        return maxi;
    }
};