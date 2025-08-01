class Solution {
  public:
    void paths(vector<vector<int>> maze, vector<vector<int>> &visited, string s, vector<string> &ans, int i,int j){
        if(i==maze.size()-1 && j==maze.size()-1){
            ans.push_back(s);
            return;
        }
        if(maze[i][j]==0) return;
        
        if(i+1<maze.size() && maze[i+1][j]==1 && find(visited.begin(),visited.end(),vector<int>{i+1,j})==visited.end()){
            s+='D';
            visited.push_back({i+1,j});
            paths(maze,visited,s,ans,i+1,j);
            s.pop_back();
            visited.pop_back();
        }
        if(j!=0 && maze[i][j-1]==1 && find(visited.begin(),visited.end(),vector<int>{i,j-1})==visited.end()){
            s+='L';
            visited.push_back({i,j-1});
            paths(maze,visited,s,ans,i,j-1);
            s.pop_back();
            visited.pop_back();
        }
        if(j+1<maze.size() && maze[i][j+1]==1 && find(visited.begin(),visited.end(),vector<int>{i,j+1})==visited.end()){
            s+='R';
            visited.push_back({i,j+1});
            paths(maze,visited,s,ans,i,j+1);
            s.pop_back();
            visited.pop_back();
        }
        if(i!=0 && maze[i-1][j]==1 && find(visited.begin(),visited.end(),vector<int>{i-1,j})==visited.end()){
            s+='U';
            visited.push_back({i-1,j});
            paths(maze,visited,s,ans,i-1,j);
            s.pop_back();
            visited.pop_back();
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        string s;
        vector<vector<int>> visited={{0,0}};
        paths(maze,visited,s,ans,0,0);
        return ans;
    }
};