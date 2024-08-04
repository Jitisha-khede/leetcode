class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size()-1;
        for(int i=0;i<=n;i++){
            sum+=mat[i][i];
            if(i!=n-i) sum+=mat[i][n-i];
        }
        return sum;
    }
};