//BRUTE: LINEAR SEARCH
//BETTER
class Solution {
  public:
    int nthRoot(int n, int m) {
        if(n==1) return m;
        int prev = -1;
        int mul = 1;
        int num =1;
        for(int i=0;i<m;i++){
            if(mul==m){
                return num;
            }
            else if(mul<m){
                prev = num;
                num*=2;
            }
            else if(mul>m){
                num--;
            }
            if(num==prev) return -1;
            mul = 1;
            for(int j=0;j<n;j++){
                mul*=num;
            }
        }
        return -1;
    }
};
//OPTIMAL
class Solution {
  public:
    int mul(int n, int m){
        int ans = 1;
        for(int i=0;i<n;i++){
            ans*=m;
        }
        return ans;
    }
    
    int nthRoot(int n, int m) {
        int l = 1;
        int h = m;
        while(l<=h){
            int mid = (l+h)/2;
            int num = mul(n,mid);
            if(m==num) return mid;
            else if(num<m){
                l=mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return -1;
    }
};