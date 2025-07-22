class Solution {
  public:
    vector<int> minPartition(int N) {
        vector<int> cur =  { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> ans;
        int i=cur.size()-1;
        
        while(N!=0){
            if(cur[i]<=N){
                N-=cur[i];
                ans.push_back(cur[i]);
            }
            else{
                i--;
            }
        }
        return ans;
    }
};