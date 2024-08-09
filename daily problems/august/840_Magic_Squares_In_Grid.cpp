class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int row  = grid.size();
        int col = grid[0].size();
        
        for(int i=0;i<=row-3;i++){
            for(int j=0;j<=col-3;j++){

                vector<vector<int>> mg(3,vector<int>(3,0));
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){
                        mg[x][y] = grid[i+x][j+y];
                    }
                }    
                if(checkmg(mg)) count++;
            }    
        }

        return count;
    }


    bool checkmg(vector<vector<int>> mg){
        unordered_map<int,int> mp;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                mp[mg[i][j]]++;
            }
        }
        for(auto& it: mp){
            if(it.second>=2 || it.first>9 || it.first < 1) return false;
        }
        int num = mg[0][0]+mg[0][1]+mg[0][2];
        if(mg[0][0]+mg[1][0]+mg[2][0]!=num) return false;
        if(mg[0][0]+mg[1][1]+mg[2][2]!=num) return false;
        if(mg[1][0]+mg[1][1]+mg[1][2]!=num) return false;
        if(mg[2][0]+mg[2][1]+mg[2][2]!=num) return false;
        if(mg[0][1]+mg[1][1]+mg[2][1]!=num) return false;
        if(mg[0][2]+mg[1][2]+mg[2][2]!=num) return false;
        if(mg[0][2]+mg[1][1]+mg[2][0]!=num) return false;
        return true;
    }
};