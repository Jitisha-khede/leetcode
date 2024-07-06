class Solution {
public:
    int passThePillow(int n, int time) {
        int temp = 0;
        int flag = 0;
        for(int i=0;i<=time;i++){
            if(temp<n && flag==0){
                temp++;
                if(temp==n){
                    temp++;
                    flag= 1;
                }
            }
            if(flag==1){
                temp--;
                if(temp==1){
                    flag = 0;
                }
            }
            cout<<temp<<" ";
        }
        return temp;
    }
};