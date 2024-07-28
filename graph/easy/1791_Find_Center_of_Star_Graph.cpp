class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int edge1 = edges[0][0],edge2 = edges[0][1], temp=0;
        for(int i=1;i<edges.size();i++){
            if(edges[i][0]==edge1) return edge1;
            else if(edges[i][1]==edge1) return edge1;
            else if(edges[i][1]==edge2) return edge2;
            else if(edges[i][0]==edge2) return edge2;
        }
        return 0;
    }
};