class Solution {
public:
    int numTeams(vector<int>& rat) {
        int count = 0;
        for(int i=0;i<rat.size()-2;i++){  
            for(int j=i+1;j<rat.size();j++){
                for(int k = j+1;k<rat.size();k++){
                    if(rat[i]>rat[j] && rat[j]>rat[k]) count++;
                    if(rat[i]<rat[j] && rat[j]<rat[k]) count++;
                }
            }   
        }
        return count;
    }
};