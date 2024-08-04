class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int cr = 0,cc=0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<grid.size();i++){
            if(grid[i].size()<=1) continue;
           
            vector<int> temp = grid[i];
            int high = temp.size()-1;
            int low = 0;
            while(low<high){
                if(temp[low]!=temp[high]) cr++;
                low++;
                high--; 
            }
        }

        vector<vector<int>> temp(n, vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) temp[i][j] = grid[j][i];
        }

        for(int i=0;i<temp.size();i++){
            if(temp[i].size()<=1) continue;
           
            vector<int> tmp = temp[i];
            int high = tmp.size()-1;
            int low = 0;
            while(low<high){
                if(tmp[low]!=tmp[high]) cc++;
                low++;
                high--; 
            }
        }

        return min(cc,cr);
    }
};