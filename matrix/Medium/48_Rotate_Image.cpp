class Solution {
public:
    void rotate(vector<vector<int>>& mat) {

        //BRUTE FORCE
        // int m = mat.size();
        // int n = mat[0].size();
        // for(int i=0;i<m;i++){
        //     vector<int> temp;
        //     for(int j=n-1;j>=0;j--){
        //         temp.push_back(mat[j][i]);
        //     }
        //     mat.push_back(temp);
        // }
        // mat.erase(mat.begin(),mat.begin()+m);

        //OPTIMAL
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m-1;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j){
                    swap(mat[i][j],mat[j][i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
        
    }
};