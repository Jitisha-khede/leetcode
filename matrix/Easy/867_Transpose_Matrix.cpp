class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> temp(n,vector<int> (m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp[i][j] = mat[j][i];
            }
        }

        return temp;
    }
};