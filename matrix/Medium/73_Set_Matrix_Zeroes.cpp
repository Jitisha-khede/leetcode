class Solution {
    public:
        void setZeroes(vector<vector<int>>& mat) {
            vector <pair <int,int>> v;
            int m=mat.size();
            int n=mat[0].size();
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][j]==0) {
                        v.push_back({i,j});
                    }
                }
            }
    
            for(int k=0;k<v.size();k++){
                int row = v[k].first;
                int col = v[k].second;
                for(int i=0;i<n;i++){
                    mat[row][i] = 0;
                }
                for(int j=0; j<m; j++){
                    mat[j][col] = 0;
                }
            }
        }
    };