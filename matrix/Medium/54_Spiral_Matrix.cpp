class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vect;
        
        int n = matrix.size();
        int m = matrix[0].size();
        int mx = (min(m,n)+1)/2;
        for(int i=0;i<mx;i++){
            for(int j=i;j<m-i;j++){
                vect.push_back(matrix[i][j]);
            }
            for(int j=i+1;j<n-i;j++){
                vect.push_back(matrix[j][m-1-i]);
            }
            if(n-1-i>i){   
                for(int j=m-i-2;j>=i;j--){
                    vect.push_back(matrix[n-1-i][j]);
                }
            }

            if(m-i-1>i){
                for(int j=n-i-2;j>i;j--){
                    vect.push_back(matrix[j][i]);
                }
            }
        }
        return vect;
    }
};                                                                                                                                                                