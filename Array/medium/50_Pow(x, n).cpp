class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        if(nn<0) nn*=-1;
        double ans = 1.0;
        while(nn>0){
            if(nn%2==0){
                x*=x;
                nn/=2;
            }
            else{
                ans*=x;
                nn--;
            }
        }
        if(n<0) return (double)(1.0)/ans;
        return ans;
    }
};