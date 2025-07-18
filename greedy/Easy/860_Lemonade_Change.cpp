class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]>5) return false;
        vector<int> v(3,0);
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) v[0]++;
            else if(bills[i]==10){
                if(v[0]<=0) return false;
                v[0]--;
                v[1]++;
            }
            else{
                if(v[0]<=0) return false;
                if(v[0]<3 && v[1]<1) return false;
                if(v[1]>0){
                    v[2]++;
                    v[1]--;
                    v[0]--;
                }
                else{
                    v[0]-=3;
                }
            }
        }
        return true;
    }
};