//BRUTE FORCE
class Solution {
public:
    bool isSafe( int row,int col,vector<string> &board, int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row=duprow;
        col=dupcol;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(vector<string> &board,int n,int col,vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row =0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(board,n,col+1,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> board(n);
       string s(n,'.');
       for(int i=0;i<n;i++){
        board[i]=s;
       }
       solve(board,n,0,ans);
       return ans;
    }
};
//OPTIMAL
class Solution {
public:
    void solve(vector<string> &board,int n,int col,vector<vector<string>> &ans,
    vector<int> &lower, vector<int> &upper, vector<int> &side){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row<n;row++){
            if(side[row]==0 && lower[row+col]==0 && upper[n-1+row-col]==0){
                board[row][col]='Q';
                side[row]=1;
                lower[row+col]=1;
                upper[n-1+row-col]=1;
                solve(board,n,col+1,ans,lower,upper,side);
                board[row][col]='.';
                side[row]=0;
                lower[row+col]=0;
                upper[n-1+row-col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> board(n);
       vector<int> lower(2*n-1,0),upper(2*n-1,0),side(n,0);
       string s(n,'.');
       for(int i=0;i<n;i++){
        board[i]=s;
       }
       solve(board,n,0,ans,lower,upper,side);
       return ans;
    }
};