class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<vector<int>> v(start.size());
        for(int i=0;i<start.size();i++){
            v[i] = {start[i],end[i]};
        }
        
        sort(v.begin(),v.end(),[](const vector<int> &a, const vector<int> &b){
            return a[1]<b[1];
        });
        
        int endTime = -1;
        int c = 0;
        
        for(int i=0;i<start.size();i++){
            if(v[i][0]>endTime){
                endTime = v[i][1];
                c++;
            }
        }
        return c;
    }
};