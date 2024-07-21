class Solution {
public:
    string losingPlayer(int x, int y) {
        bool flag=0;
        while(x>0 && y>=4){
            if(flag==0){
                x--;
                y-=4;
                flag = 1;
            }
            else{
                x--;
                y-=4;
                flag = 0;
            }
        }
        if(flag==0) return "Bob";
        return "Alice";
    }
};