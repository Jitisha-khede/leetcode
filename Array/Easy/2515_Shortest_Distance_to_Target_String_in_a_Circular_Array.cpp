class Solution {
public:
    int closetTarget(vector<string>& words, string target, int si) {
        int c=0,n=words.size();
        int ans=INT_MAX;
        for(int i=si;i<n*2-1;i++){
            if(words[i%n]==target){
                if(n-c<ans || c<ans){
                    if(n-c>=0) ans = min(n-c,c);
                }
            }
            c++;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};