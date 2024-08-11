class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = countIsIsland(grid);

        if(count!=1){
            return 0;
        }

        else{
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    if(grid[i][j]==1){
                        grid[i][j] = 0;
                        count = countIsIsland(grid);
                        grid[i][j] = 1;
                        if(count!=1) return 1;
                    }
                }
            }
        }
        return 2;
    }

    int countIsIsland(vector<vector<int>> & grid){
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;
        set<pair<int,int>> st;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && st.find({i,j})==st.end()){
                    mark(grid,i,j,r,c,st);
                    count++;
                }
            }
        }
        return count;
    }


    void mark(vector<vector<int>>& grid,int x, int y, int row,int col,set<pair<int,int>>& st){
        if(x<0 || x>=row || y<0 || y>=col || grid[x][y]!=1 ||  st.find({x, y}) != st.end()) return;

        st.insert({x,y});

        mark(grid,x+1,y,row,col,st);
        mark(grid,x-1,y,row,col,st);
        mark(grid,x,y+1,row,col,st);
        mark(grid,x,y-1,row,col,st);
    }
};