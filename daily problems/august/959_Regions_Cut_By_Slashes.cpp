class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<int>> exgrid (grid.size()*3,vector<int> (grid.size()*3,0));
        int count =0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                int r = i*3;
                int c = j*3;

                if(grid[i][j]=='\\'){
                    exgrid[r][c] = 1;
                    exgrid[r+1][c+1] = 1;
                    exgrid[r+2][c+2] = 1;
                }
                else if(grid[i][j]=='/'){
                    exgrid[r][c+2] = 1;
                    exgrid[r+1][c+1] = 1;
                    exgrid[r+2][c] = 1;
                }
            }
        }
        
        int row = exgrid.size();
        int col = exgrid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(exgrid[i][j]==0){
                    mark(exgrid,i,j,row,col);
                    count++;
                    
                }
            }
        }
        return count;
    }

    void mark(vector<vector<int>>& exgrid,int x, int y, int row, int col){
        if(x<0 || x>=row || y<0 || y>=col || exgrid[x][y]!=0) return;

        exgrid[x][y]=2;

        mark(exgrid,x+1,y,row,col);
        mark(exgrid,x-1,y,row,col);
        mark(exgrid,x,y+1,row,col);
        mark(exgrid,x,y-1,row,col);
    }
};