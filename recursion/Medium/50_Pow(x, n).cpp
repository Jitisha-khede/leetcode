class Solution {
public:

    double pow(double x, long long n, double ans){
        if(n==0) return ans;

        if(n%2==0) return pow(x*x,n/2,ans);
        if(n%2!=0) return pow(x,n-1,ans*x);

        return ans; 
    }
    
    double myPow(double x, int n) {
        long long nn = n;
        if(nn<0) nn*=-1;
        double ans = pow(x,nn,1.0);
        if(n<0) return (double)(1.0)/ans;
        return ans;
    }
};