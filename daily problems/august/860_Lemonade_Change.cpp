class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int bills5=0,bills10=0;
        if(bills[0]!=5)return false;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==10){
                if(bills5==0) return false;
                else bills5-=5, bills10+=10;
            }
            else if(bills[i]==20){
                if(bills10==0 && bills5<15 || bills5<5) return false;
                else{
                    if(bills10!=0) bills10-=10,bills5-=5;
                    else bills5-=15;
                }
            }
            else bills5+=5;
        }
        return true;
    }
};