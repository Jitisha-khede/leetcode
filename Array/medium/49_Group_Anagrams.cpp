class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> copy = strs;
        vector<int> visited(strs.size(),0);
        for(int i=0;i<strs.size();i++){
            sort(copy[i].begin(),copy[i].end());
        }
        for(int i=0;i<strs.size();i++){
            if (visited[i]) continue;
            vector<string> temp = {strs[i]};
            visited[i] = 1;
            for(int j=i+1;j<strs.size();j++){
                if(visited[j]==0 && copy[i]==copy[j]){
                    temp.push_back(strs[j]);
                    visited[j]=1;
                }
            }
            res.push_back(temp);
        }
        return res;       
    }
};