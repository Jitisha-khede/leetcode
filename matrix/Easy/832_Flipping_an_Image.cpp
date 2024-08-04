class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& img) {
        vector<vector<int>> ans;
        for(int i=0;i<img.size();i++){
            vector<int> temp;
            temp = img[i];
            reverse(temp.begin(),temp.end());
            for(int j=0;j<temp.size();j++){
                if(temp[j]==0) temp[j] = 1;
                else if(temp[j]==1) temp[j] = 0; 
            }
            ans.push_back(temp);
        }
        return ans;
    }
};